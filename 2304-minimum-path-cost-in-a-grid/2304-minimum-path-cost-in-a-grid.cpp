class Solution {
public:

         int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& cost, vector<vector<int>>& memo){
        if(i==grid.size()-1){
            return grid[i][j];
        }
        if(memo[i][j]!=-1) return memo[i][j];
        int tempans=INT_MAX;
        for(int k=0; k < grid[0].size(); k++){
           tempans = min(tempans,  grid[i][j] + cost[grid[i][j]][k] + dfs(i+1, k, grid, cost, memo));           
        }
        return memo[i][j] = tempans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int m=grid[0].size(), n=grid.size();
        int ans=INT_MAX;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        for(int i=0;i<m;i++){
            ans=min(ans, dfs(0, i, grid, cost, memo));
        }
        return ans;
    }
};