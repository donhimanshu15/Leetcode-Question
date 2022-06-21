class Solution {
    
public:
 
      
        int f(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
      if(amount==0) return 0;
        if( amount<0 || i<0) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
     
        return dp[i][amount]=min(f(i-1,amount,coins,dp),1+f(i,amount-coins[i],coins,dp));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans=f(coins.size()-1,amount,coins,dp);
        return ans>=1e9?-1:ans;
    }
};