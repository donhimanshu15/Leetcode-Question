class Solution {
public:
    int dx[4]={-1,0,0,1};
    int  dy[4]={0,-1,1,0};
   void solve(vector<vector<int>>& grid, int i, int j, int &cnt){
        cnt=cnt+1;
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<0 || y <0 || x>=grid.size() || y>=grid[0].size()) continue;
            if(grid[x][y]==0) continue;
            
            solve(grid,x,y,cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    solve(grid,i,j,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        if(ans==INT_MIN) return 0 ;
        else return ans;
    }
    
};