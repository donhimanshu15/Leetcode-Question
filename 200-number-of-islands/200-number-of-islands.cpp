class Solution {
public:
    bool verify(int n,int m,int x,int y)
    { 
        return (x<n && y<m && x>=0 && y>=0);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();//rows
        int m = grid[0].size();//columns
        int varX[4] = {-1,0,0,1};
        int varY[4] = {0,-1,1,0};
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && visit[i][j] == false)
                { 
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visit[i][j] = true;
                    count++;
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k = 0;k<4;k++)
                        {
                            if(verify(n,m,x+varX[k],y+varY[k]) && grid[x+varX[k]][y+varY[k]] == '1' && visit[x+varX[k]][y+varY[k]] == false)
                            {
                                visit[x+varX[k]][y+varY[k]] = true;
                                q.push({x+varX[k],y+varY[k]});
                                
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};