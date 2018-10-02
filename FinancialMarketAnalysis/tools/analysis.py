"""MC1-P1: Analyze a portfolio."""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import datetime as dt
from util import get_data, plot_data

def assess_portfolio(sd = dt.datetime(2008,1,1), ed = dt.datetime(2009,1,1), \
    syms = ['GOOG','AAPL','GLD','XOM'], \
    allocs=[0.2,0.3, 0.4, 0.1], \
    sv=1000000, rfr=0.0, sf=252.0, \
    gen_plot=False):

    
    
    # Read in adjusted closing prices for given symbols, date range
    dates = pd.date_range(sd, ed)
    prices_all = get_data(syms, dates)  # automatically adds SPY
    prices = prices_all[syms]  # only portfolio symbols
    prices_SPY = prices_all['SPY']  # only SPY, for comparison later
    

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
        
    # Get portfolio statistics (note: std_daily_ret = volatility)
    #cr, adr, sddr, sr = [0, 0, 0, 0]
    cr, adr, sddr, sr = compute_portfolio_stats(port_val, allocs, rfr = 0.0, sf = 252.0)
    
    
    # Compare daily portfolio value with SPY using a normalized plot
    if gen_plot:
        # add code to plot here
        df_temp = pd.concat([port_val, normalized_prices_SPY], keys=['Portfolio', 'SPY'], axis=1)
        plot_data(df_temp)
        pass

    # compute end value
    ev = port_val.at[port_val.last_valid_index()]
    
    return cr, adr, sddr, sr, ev

def compute_portfolio_stats(prices = pd.DataFrame(), allocs=[0.1,0.2,0.3,0.4], rfr = 0.0, sf = 252.0):
    # compute cumlative return
    cr = (prices.loc[prices.last_valid_index()]-prices.loc[prices.first_valid_index()])/prices.loc[prices.first_valid_index()]

    # get daily return
    daily_return = prices.copy()
    daily_return[1:] = (prices[1:]/prices[:-1].values) - 1
    daily_return[0] = 0

    # get avg of daily return
    adr = daily_return[1:].mean()

    # get std of daily return
    sddr = daily_return[1:].std()
    
    sr = np.sqrt(sf) * adr/sddr
    
    return cr, adr, sddr, sr

def volatility(allocs=[0.2, 0.2, 0.2, 0.2, 0.2], prices = pd.DataFrame, syms=['SPY', 'GOOG', 'IBM', 'GLD', 'AAPL']):


    sv = 1000000
               
    # normalized data in "normalized_prices" dataframe
    normalized_prices = prices.copy()
    #print normalized_prices[0:11]
    
    for symbol in normalized_prices:
        normalized_prices[symbol] = (normalized_prices[symbol])/(prices.at[prices.first_valid_index(), symbol])
        
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
    
    # get daily return
    daily_return = port_val.copy()
    daily_return[1:] = (port_val[1:]/port_val[:-1].values) - 1
    daily_return[0] = 0

    # get std of daily return
    sddr = daily_return[1:].std()
    
    return sddr

def test_code():
    # This code WILL NOT be tested by the auto grader
    # It is only here to help you set up and test your code

    # Define input parameters
    # Note that ALL of these values will be set to different values by
    # the autograder!
    start_date = dt.datetime(2010,01,01)
    end_date = dt.datetime(2012,12,31)
    symbols = ['GOOG', 'AAPL', 'GLD', 'XOM']
    allocations = [0.2, 0.3, 0.4, 0.1]
    start_val = 1000000  
    risk_free_rate = 0.0
    sample_freq = 252

    # Assess the portfolio
    cr, adr, sddr, sr, ev = assess_portfolio(sd = start_date, ed = end_date,\
        syms = symbols, \
        allocs = allocations,\
        sv = start_val, \
        gen_plot = True)

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
    test_code()
