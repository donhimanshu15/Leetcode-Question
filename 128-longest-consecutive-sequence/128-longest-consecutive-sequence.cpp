class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int>se(nums.begin(), nums.end());
        int maxl=0;
        for(auto &x : nums){
            int len=1;
            if(se.find(x-1) != se.end()){
                continue;
            }
            
            else{
                while(se.find(x+1) != se.end()){
                    len++;
                    x++;
                }
            }
            maxl = max(maxl, len);
        }
        return maxl;
    }
};