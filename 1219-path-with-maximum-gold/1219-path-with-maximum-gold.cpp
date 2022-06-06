class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int sum=0,path=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false&&grid[i][j]!=0){
                    solve(grid,n,m,vis,sum,i,j,path);
                }
            }
        }
        return(sum);
    }
    void solve(vector<vector<int>>& grid,int n,int m,vector<vector<bool>> &vis,int &sum,int         i,int j,int &path){
        vis[i][j]=true;
        path+=grid[i][j];
        sum=max(sum,path);
        if(i+1<n&&grid[i+1][j]!=0&&vis[i+1][j]==false){
            solve(grid,n,m,vis,sum,i+1,j,path);
        }
        if(i-1>=0&&grid[i-1][j]!=0&&vis[i-1][j]==false){
            solve(grid,n,m,vis,sum,i-1,j,path);
        }
        if(j+1<m&&grid[i][j+1]!=0&&vis[i][j+1]==false){
            solve(grid,n,m,vis,sum,i,j+1,path);
        }
        if(j-1>=0&&grid[i][j-1]!=0&&vis[i][j-1]==false){
            solve(grid,n,m,vis,sum,i,j-1,path);
        }
        path-=grid[i][j];
        vis[i][j]=false;
    }
};