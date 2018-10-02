"""MC2-P1: Market simulator."""

import pandas as pd
import numpy as np
import datetime as dt
import os
from util import get_data, plot_data
from analysis import compute_portfolio_stats

def compute_portvals(orders_file = "./orders/orders.csv", start_val = 1000000):
    # this is the function the autograder will call to test your code
    
    # df of order info
    orders_df = pd.read_csv(orders_file, index_col='Date', parse_dates=True, na_values=['nan'])
    orders_df = orders_df.sort_index(axis=0)
    
    # Step 1: find start date, end date and symbols. (from orders file) 
    start_date = orders_df.first_valid_index()
    end_date = orders_df.last_valid_index()
    dates = pd.date_range(start_date, end_date)
    stks = list(set(orders_df['Symbol']))

    # Step 2: create prices dataframe
    prices = get_data(stks, dates)
    prices = prices[stks]
    temp_cash = pd.DataFrame(1, index = dates, columns = ['cash'])
    prices = prices.join(temp_cash, how='left')
    
    # Step 3: create trades dataframe
    trades = prices.copy()
    trades.loc[:,:] = 0
    for row in orders_df.itertuples():
        # extract data
        date = row.Index
        sym = row.Symbol
        order = row.Order
        shares = row.Shares
        price = prices.at[date, sym] # price of share on that date

        # Transaction costs
        trades.loc[date, 'cash'] -= 9.95 # commissions
        market_impact = float("{:.3f}".format(.005*(price*shares)))
        trades.loc[date, 'cash'] -= market_impact
        
        
        # stats used for leverage calculation
        totals = trades.sum(axis=0)*prices.loc[date,:]
        cash = start_val + totals['cash']
        investments = sum(totals[totals.index != 'cash'])
        
        if order == 'BUY':
            # leverage check
            cash -= (price*shares)
            investments += (price*shares)
            leverage = (abs(investments)/(investments+cash))
            
            if leverage <= 2.0:
                trades.loc[date, sym] += shares
                trades.loc[date, 'cash'] += (price * shares) * -1
        else:
            # leverage check
            cash += (price*shares)
            investments -= (price*shares)
            leverage = (abs(investments)/(investments+cash))
            
            if leverage <= 2.0:
                trades.loc[date, sym] -= shares
                trades.loc[date, 'cash'] -= (price * shares) * -1
    print trades
    # Step 4: create holdings dataframe
    holdings = trades.copy()
    holdings.loc[:,:] = 0
    holdings.loc[start_date,:] = trades.loc[start_date,:] # initialize share holdings of first row
    holdings.loc[start_date,'cash'] = trades.loc[start_date,'cash']+start_val # initialize cash of first row
    for i in range(1, len(holdings)):
        holdings.iloc[i,:] = holdings.iloc[i-1,:] + trades.iloc[i,:]

    # Step 5: create values dataframe
    values = holdings.copy()
    values = prices*holdings

    # Step 6: create portvals dataframe
    portvals = values.sum(axis=1).to_frame()
    portvals = portvals.rename(columns={0:'portval'})
    return portvals
def test_code():

    # see format of [order].csv in orders directory
    of = "./orders/orders2.csv"
    sv = 1000000

    # Process orders
    portvals = compute_portvals(orders_file = of, start_val = sv)
    print portvals
    if isinstance(portvals, pd.DataFrame):
        portvals = portvals[portvals.columns[0]] # just get the first column
    else:
        "warning, code did not return a DataFrame"
    
    # plot with spy to compare
    start_date = portvals.index[0]
    end_date = portvals.index[-1]
    
    dates = pd.date_range(start_date, end_date)
    temp = get_data(['GOOG'], dates)
    SPY = temp['SPY']
    
    normalized_prices_SPY = SPY.copy()
    normalized_prices_SPY = (normalized_prices_SPY)/SPY[0]
    
    normalized_portval = portvals.copy()
    normalized_portval = (normalized_portval)/portvals[0]
    
    df_temp = pd.concat([normalized_portval, normalized_prices_SPY], keys=['Portfolio', 'SPY'], axis=1)
    plot_data(df_temp)
    
if __name__ == "__main__":
    test_code()
