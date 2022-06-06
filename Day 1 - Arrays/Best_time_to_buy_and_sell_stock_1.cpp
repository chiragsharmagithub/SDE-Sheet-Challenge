// Best time to buy and sell stock 1
// Question link: 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Logic,
// We have to find the max profit
// profit we receive after buying a stock at a lower price a compared to the price when we sell it.

// While iterating through all the elements of array,
// We'll check if there the current price is the lowest of all time, and 
// while moving forward we will check if the difference of mini and current price is maximum
// and set the profit variable to that maximum difference.


// Chirag 
// TC: O(N)
// SC: O(1)

// where N = size of prices array

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = INT_MAX;
        for(int i: prices) {
            mini = min(mini, i);
            int tempProfit = i - mini;
            profit = max(profit, tempProfit);
        }
    return profit;
    }
};