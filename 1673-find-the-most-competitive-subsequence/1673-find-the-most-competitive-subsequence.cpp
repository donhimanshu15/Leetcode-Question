class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int> st;
        
       
        int times=n-k;
        for(int i=0;i<n;i++){
            while(!st.empty() and times and nums[i]<st.top()){
                st.pop();
                times--;
            }
            st.push(nums[i]);
        }
       
        vector<int> ans;
      
        while(st.size()>k){
            st.pop();
        }
        
        while(st.size()){
            int t=st.top();
            ans.push_back(t);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};