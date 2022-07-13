class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> ans;
        vector<int> left(nums.size()+1);
        vector<int> right(nums.size()+1);
        left[0]=1;
        right[nums.size()]=1;
        for(int i=0;i<nums.size();i++)
            left[i+1] = left[i]*nums[i];
        
        for(int i=nums.size()-1;i>=0;i--)
            right[i] = right[i+1]*nums[i];
        
        for(int i=1;i<=nums.size();i++){
            int a= right[i]*left[i-1];
            ans.push_back(a);
        }
        return ans;
    }
};