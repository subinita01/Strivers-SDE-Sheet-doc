// https://leetcode.com/problems/min-cost-climbing-stairs/
// Time Complexity: O(n) where n is the number of stairs
// Space Complexity: O(n) for the dp array + O(n) for recursion stack
// Recursion + Memoization approach
// LC 746. Min Cost Climbing Stairs

class Solution {
public:

    int minCost(vector<int>& cost, vector<int>& dp, int n){
        //base case
        if(n==0 || n==1) return cost[n];
        //check 
        if(dp[n]!=-1) return dp[n];
        //recursive relation
        dp[n] = cost[n] + min(minCost(cost,dp,n-1),minCost(cost,dp,n-2));
        return dp[n];
  

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        int ans = min(minCost(cost,dp,n-1),minCost(cost,dp,n-2));
        return ans;
        
    }
};

