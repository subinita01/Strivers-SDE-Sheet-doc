// https://leetcode.com/problems/coin-change/
// Time Complexity: O(S*n) where S is the amount and n is the number of coins
// Space Complexity: O(S) for the dp array + O(S) for recursion stack
// Recursion + Memoization  approach
// LC 322. Coin Change

class Solution {
public:
    int minCoin(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans = INT_MAX;
        
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int out = minCoin(coins, amount - coins[i], dp);
                if (out!=INT_MAX) {
                    ans = min(ans,out+1);
                }
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1); //return dp[amount]
        int res = minCoin(coins, amount,dp);
        return (res==INT_MAX)?-1:res;
    }
};