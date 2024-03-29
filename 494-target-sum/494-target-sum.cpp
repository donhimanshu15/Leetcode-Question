class Solution {
public:
    int total=0;
    int solve(vector<int> &nums,int i,int n,int sum,int target,vector<vector<int> > &memo)
    {
        if(i==n)
        {
            if(sum==target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
        if(memo[i][total+sum]!=INT_MIN)
        {
            return memo[i][total+sum];
        }
        int add=solve(nums,i+1,n,sum+nums[i],target,memo);
        int sub=solve(nums,i+1,n,sum-nums[i],target,memo);     
        return memo[i][total+sum]=add+sub;
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int n=nums.size();
        vector<vector<int>> memo(n+1,vector<int>(total*2+1,INT_MIN));
        return solve(nums,0,nums.size(),0,target,memo);
    }
};