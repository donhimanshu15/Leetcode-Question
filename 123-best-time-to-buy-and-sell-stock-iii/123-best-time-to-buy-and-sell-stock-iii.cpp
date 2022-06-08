class Solution {
    vector<vector<vector<int>>> dp;
    int f(int ind,int buy, int cap, vector<int> &prices ){
        if(cap==0|| ind>=prices.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int result=f(ind+1,buy,cap,prices);
        if(buy){
          result=max(result,-prices[ind]+f(ind+1,0,cap,prices));
        }
        else{
            result=max(result,prices[ind]+f(ind+1,1,cap-1,prices));
        }
        dp[ind][buy][cap]=result;
        return result;
    }
public:
    int maxProfit(vector<int>& prices) {
       
     dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
         return f(0,1,2,prices);
    }
};