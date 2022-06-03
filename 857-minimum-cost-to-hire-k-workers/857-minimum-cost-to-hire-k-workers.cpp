class Cmp{
    public:
    bool operator()(pair<double,int> &a,pair<double,int> &b){
        return a.second<b.second;
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
         vector<pair<double,int>> v;
        int n=q.size();
        for(int i=0;i<n;i++){
            v.push_back({(double)w[i]/q[i],q[i]});
        }
        sort(v.begin(),v.end());
        int sum=0;
        double ans=INT_MAX;
         priority_queue<pair<double,int>,vector<pair<double,int>>,Cmp> h;
         for(int i=0;i<k-1;i++){
            sum+=v[i].second;
            h.push(v[i]);
        }
         for(int i=k-1;i<n;i++){
            sum+=v[i].second;
            h.push(v[i]);
            if(ans>sum*v[i].first)ans=sum*v[i].first;
            if(h.size()>k-1){
                auto z=h.top();h.pop();
                sum-=z.second;
            }
            
        }
        
        return ans;
    }
};