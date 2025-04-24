class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int dis=0;
        int n=nums.size();
        map<int,int> m;
        map<int,int> m1;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ms= m.size();
        int i=0,j=0;
        while(j<n){
     m1[nums[j]]++;
     while(m1.size()== ms){
         dis=dis+(n-j);
        
         if(m1[nums[i]]==1) m1.erase(nums[i]);
         else m1[nums[i]]--;
          i++;
     }
j++;
        }
        return dis;
    }
};