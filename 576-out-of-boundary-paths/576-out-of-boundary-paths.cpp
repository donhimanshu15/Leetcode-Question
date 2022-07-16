class Solution {
public:
    int mod = pow(10,9) + 7;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int solve(int m, int n, int N, int i, int j,vector<vector<vector<int>>> &dp , int moves){
             if(i < 0 || j < 0 || i >= m || j >= n){
            return 1;
        }
              if(moves == N){
            return 0;
        }
        if(dp[moves][i][j] != -1){
            return dp[moves][i][j] % mod;
        }
        int temp=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            temp=(temp+solve(m,n,N,x,y,dp,moves+1))%mod;
            
        }
        return dp[moves][i][j]=temp % mod;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
       return solve(m,n,N,i,j,dp,0);
    }
};