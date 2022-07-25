class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int s=0;
        int e=nums.size()-1;
        int mid;
        int si=-1;
        int ei=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                if(mid==s or nums[mid]!=nums[mid-1]){
                si=mid;
                break;}
             else{   
                 e=mid-1;
                 si=mid-1;
           }
                
            }
          else  if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        s=0;
         e=nums.size()-1;

        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                 if(mid==e or nums[mid]!=nums[mid+1]){
                ei=mid;
                break;}
             else{   
                 s=mid+1;
                 ei=mid+1;
           }
            }
          else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        ans.push_back(si);
        ans.push_back(ei);
        return ans;
    }
};