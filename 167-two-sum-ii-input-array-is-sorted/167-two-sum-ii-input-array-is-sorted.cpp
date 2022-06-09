class Solution {
public:
    vector<int> twoSum(vector<int>& number, int target) {
     int i=0;
        vector<int> ans;
        int j=number.size()-1;
        while(j>i){
            if(number[i]+number[j]==target) break;
          else if(number[i]+number[j]>target){
              j--;
          }  
            else{
                i++;
            }
        }
        ans.push_back(i+1);
         ans.push_back(j+1);
        return ans;
        
    }
};