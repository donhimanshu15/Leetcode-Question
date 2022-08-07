class Solution {
public:
	int dp[100005];
	int help(int i,vector<int>&nums){
		if(i>=size(nums)) return 1;
		
		if(dp[i]!=-1) return dp[i];
        int a=0,b=0,c=0;
		if(i+2<size(nums) and nums[i+1]==nums[i] and nums[i+1]==nums[i+2])  a=help(i+3,nums);
		if(i+2<size(nums) and nums[i+1]-1==nums[i] and nums[i+1]==nums[i+2]-1) b =help(i+3,nums);
		if(i+1<size(nums) and nums[i+1]==nums[i]) c =help(i+2,nums);
		return dp[i] = a or b or c;
	}

	bool validPartition(vector<int>& nums) {
		memset(dp,-1,sizeof dp);
		return help(0,nums);
	}
};