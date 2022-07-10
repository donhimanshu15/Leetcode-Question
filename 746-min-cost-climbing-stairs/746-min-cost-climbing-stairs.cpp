class Solution {
public:
    int solve(vector<int>& cost,vector<int>& dp, int idx){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]= cost[idx]+min(solve(cost,dp,idx+1),solve(cost,dp,idx+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        int ans1= solve(cost,dp,0);
        int ans2=solve(cost,dp,1);
        return min(ans1,ans2);
    }
};