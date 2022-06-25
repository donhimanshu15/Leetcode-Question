class Solution {
public:
    void dfs( vector<bool> &vis, vector<int> g[], int node,int n,long long &cnt){
        vis[node]=true;
        cnt=cnt+1;
        for(auto& x:g[node]){
            if(!vis[x]){
                dfs(vis,g,x,n,cnt);
            }
           
        }
       
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        
        vector<int> g[n];
        long long ans=((long long) n*(n-1))/2;;
        for(int i=0;i<edges.size();i++){
           
            g[edges[i][0]].push_back(edges[i][1]);
             g[edges[i][1]].push_back(edges[i][0]);
            
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
               long long cnt=0;
                dfs(vis,g,i,n,cnt);
                   
                ans -= (cnt*(cnt-1))/2;
            }
        }
             
               return ans;
               
    }
};