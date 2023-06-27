//https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_8230746?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini = INT_MAX;
    int profit = 0;
    for(int i =0; i< prices.size(); i++)
    {
        mini = min(mini,prices[i]);

        profit = max((prices[i] - mini) , profit);
    }

    return profit;
}