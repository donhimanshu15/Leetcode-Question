class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans(n);
        stack<pair<int,int>> s;
        if(n>0) s.push({prices[0],0});
        for(int i=1;i<n;i++){
           while(!s.empty() && s.top().first>=prices[i]) {
            ans[s.top().second]=s.top().first-prices[i];
            s.pop();
           
           }
            s.push({prices[i],i});
        }
        while(!s.empty()){
            ans[s.top().second]=s.top().first;
            s.pop();
        }
        return ans;
    }
};