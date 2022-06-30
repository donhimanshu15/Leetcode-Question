class Solution {
public:
    int solve( vector<vector<vector<int>>> &dp, int k,int i ,int buy, vector<int>& prices,int n ){
       if(k==0 || i>=n) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy==0){
          int  a=-prices[i]+solve(dp,k,i+1,1,prices,n);
        int b=solve(dp,k,i+1,0,prices,n);
            return dp[i][buy][k]=max(a,b);
        }
        else{
             int  c= prices[i]+solve(dp,k-1,i+1,0,prices,n);
        int d=solve(dp,k,i+1,1,prices,n);
            return dp[i][buy][k]=max(c,d);
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
        return solve(dp,k,0,0,prices,n);
    }
};