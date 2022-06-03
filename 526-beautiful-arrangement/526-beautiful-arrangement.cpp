class Solution {
public:
   int count = 0;
    void solve(vector<int> &nums,int index)
    {
        if(index == nums.size())
        {
            count++;
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]!=-1)
            {
                int a = nums[i];
                if(a%(index+1) != 0 &&  (index+1)%a  != 0 )
                {
                   continue;
                }
                
                nums[i] = -1;
                solve(nums,index+1);
                
                nums[i] = a;
            }
        }
        
     }
    int countArrangement(int n) {
       vector<int> nums;
        
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
                                                                                                                                                
        int index=0;
      solve(nums,index);
        return count;
    }
};