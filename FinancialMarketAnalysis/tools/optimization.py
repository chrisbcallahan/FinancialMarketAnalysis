"""MC1-P2: Optimize a portfolio."""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import datetime as dt
import scipy.optimize as spo
from util import get_data, plot_data
from analysis import volatility, compute_portfolio_stats

def optimize_portfolio(sd=dt.datetime(2008,1,1), ed=dt.datetime(2009,1,1), \
    syms=['GOOG','AAPL','GLD','XOM'], gen_plot=False):

    # Read in adjusted closing prices for given symbols, date range
    dates = pd.date_range(sd, ed)
    prices_all = get_data(syms, dates)  # automatically adds SPY
    prices = prices_all[syms]  # only portfolio symbols
    prices_SPY = prices_all['SPY']  # only SPY, for comparison later
    sv = 1000000
    
    # find the allocations for the optimal portfolio
    # note that the values here ARE NOT meant to be correct for a test case

    
    guess = []
    for symbols in syms:
        guess.append(1.0/len(syms))

    bounds = []
    for symbols in syms:
        bounds.append((0.0, 1.0))
     
    constraints = ({'type': 'eq', 'fun': lambda x: 1.0 - np.sum(x) })
    res = spo.minimize(volatility, guess, args=(prices, syms), bounds=bounds, constraints=constraints)
    allocs = res.x
    
    ############################################################################################################
    # CODE FROM analysis.py
    ############################################################################################################

    # normalized data in "normalized_prices" dataframe
    normalized_prices = prices.copy()
    #print normalized_prices[0:11]
    
    for symbol in normalized_prices:
        normalized_prices[symbol] = (normalized_prices[symbol])/(prices.at[prices.first_valid_index(), symbol])   

    # normalize the SPY prices
    normalized_prices_SPY = prices_SPY.copy() # normalized SPY for comparison
    normalized_prices_SPY = (normalized_prices_SPY)/prices_SPY[0]   
   
    
    # Get daily portfolio value
    allocs_prices = normalized_prices.copy()
    i = 0
    # multiply by allocation
    for symbols in prices:
        allocs_prices[symbols] = normalized_prices[symbols]*allocs[i]
        i = i+1
    
    # multiply by sv to get pos_val (position value)
    pos_val = allocs_prices.copy()
    for symbols in pos_val:
        pos_val[symbols] = pos_val[symbols]*sv
        
    # get daily portfolio value
    port_val = pd.DataFrame
    port_val = allocs_prices.sum(axis=1)
        
    # Get portfolio statistics (note: std_avg_daily_ret = volatility)
    cr, adr, sddr, sr = compute_portfolio_stats(port_val, allocs, rfr = 0.0, sf = 252.0)

    # Compare daily portfolio value with SPY using a normalized plot
    if gen_plot:
        # add code to plot here
        df_temp = pd.concat([port_val, normalized_prices_SPY], keys=['Portfolio', 'SPY'], axis=1)
        plot_data(df_temp)
        pass

    ##########################################################################################################
    ##########################################################################################################

    return allocs, cr, adr, sddr, sr


def test_code():

    # define input parameters
    start_date = dt.datetime(2010,1,1)
    end_date = dt.datetime(2012,12,31)
    symbols = ['AAPL', 'XOM', 'IBM', 'GLD']

    # Assess the portfolio
    allocations, cr, adr, sddr, sr = optimize_portfolio(sd = start_date, ed = end_date,\
        syms = symbols, gen_plot = True)

    # Print statistics
    print "Start Date:", start_date
    print "End Date:", end_date
    print "Symbols:", symbols
    print "Allocations:", allocations
    print "Sharpe Ratio:", sr
    print "Volatility (stdev of daily returns):", sddr
    print "Average Daily Return:", adr
    print "Cumulative Return:", cr

if __name__ == "__main__":
    # This code WILL NOT be called by the auto grader
    # Do not assume that it will be called
    test_code()
