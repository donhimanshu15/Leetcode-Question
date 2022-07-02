class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &x:nums){
            pq.push(x);
        }
        while(k--){
            int a=pq.top()+1;
            pq.pop();
            pq.push(a);
        }
        long long ans=1;
        while(pq.size()){
            ans= (ans * pq.top())%1000000007;
            pq.pop();
        }
        return ans%1000000007;
    }
};