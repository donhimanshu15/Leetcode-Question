class Solution {
public:
vector<vector<int>> dp;
    int solve(int m,int n){
        if(n<1 || m<1) return 0;
        if(n==1 && m==1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n] = solve(m,n-1)+solve(m-1,n);
    }
    int uniquePaths(int m, int n) {

    dp.assign(m+1, vector<int>(n+1, -1));
       return solve(m,n);
    }
};