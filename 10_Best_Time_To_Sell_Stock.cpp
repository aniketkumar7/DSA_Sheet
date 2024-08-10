// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input : prices = [ 7, 1, 5, 3, 6, 4 ]
// Output : 5
// Explanation : Buy on day 2(price = 1) and sell on day 5(price = 6), profit = 6 - 1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include <bits/stdc++.h>
using namespace std;

// Brute force approach to find the maximum profit
int maxProfitBruteForce(vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();

    for (int i = 0; i < n; i++)
    { // Buy day
        for (int j = i + 1; j < n; j++)
        {                                       // Sell day
            int profit = prices[j] - prices[i]; // Calculate profit
            if (profit > maxProfit)
            {
                maxProfit = profit; // Update max profit
            }
        }
    }
    return maxProfit; // Return the maximum profit found
}

// Optimized approach to find the maximum profit
int maxProfitOptimized(vector<int> &prices)
{
    int minPrice = INT_MAX; // Initialize minPrice to a very high value
    int maxProfit = 0;      // Initialize maxProfit to 0

    for (int price : prices)
    {
        if (price < minPrice)
        {
            minPrice = price; // Update minPrice if current price is lower
        }
        else
        {
            int profit = price - minPrice; // Calculate potential profit
            if (profit > maxProfit)
            {
                maxProfit = profit; // Update maxProfit if profit is higher
            }
        }
    }
    return maxProfit; // Return the maximum profit found
}


int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }
    cout << "The maximum profit is: " << maxProfitBruteForce(prices) << endl;
    cout << "The maximum profit is: " << maxProfitOptimized(prices) << endl;
    return 0;
}