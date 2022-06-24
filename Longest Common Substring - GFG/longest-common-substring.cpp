// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
int lcs(int i, int j,string &S1, string &S2,vector<vector<int>>&dp,int &ans)
   {
       int take=0,nottake1=0,nottake2=0;
       if(i<0||j<0) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       if(S1[i]==S2[j]) 
       {
       take=1+lcs(i-1,j-1,S1,S2,dp,ans);
       }
       
       
       nottake1=lcs(i-1,j,S1,S2,dp,ans);
       nottake2=lcs(i,j-1,S1,S2,dp,ans);
       
       ans=max(ans,take);
       return dp[i][j]=take;
   }
  
   
   
   
   int longestCommonSubstr (string S1, string S2, int n, int m)
   {
       
       vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
       int ans=0;
       
       lcs(n-1,m-1,S1,S2,dp,ans);
       return ans;
   }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends