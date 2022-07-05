class Solution {
public:
    int arrayNesting(vector<int>& nums) {
       
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
         int cnt=0;
       while(i<nums.size()){
            if(nums[i]==-1) break;
        else {
            cnt++;
            int temp=nums[i];
            nums[i]=-1;
            i=temp;
            
        }
       }
        ans=max(ans,cnt);
        }
     return ans;   
    }
};