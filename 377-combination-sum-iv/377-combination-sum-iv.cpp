class Solution {
public:
    int dp[1001];
    int solve(vector<int>& nums, int target){
        if(target==0) return 1;
        if(target<0 ) return 0;
        if(dp[target]!=-1) return dp[target];
       int res=0;
        for(int i:nums)
        {
            res+=solve(nums,target-i);
        }
        return dp[target]=res;
       
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target);
    }
};