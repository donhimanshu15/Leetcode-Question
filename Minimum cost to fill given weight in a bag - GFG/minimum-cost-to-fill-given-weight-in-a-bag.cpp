// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
   public:
   int helper(int cost[],int n,int w,int i,vector<vector<int>> &dp){
       if( w==0)return 0;
       if(i>=n or w<0)return 1e9;
       if(dp[i][w]!=-1)return dp[i][w];
   
       if(cost[i]!=-1){
           return dp[i][w]=min(cost[i]+helper(cost,n,w-(i+1),i,dp),helper(cost,n,w,i+1,dp));
           
       }
       else{
          return dp[i][w]=helper(cost,n,w,i+1,dp);
       }
       
   }
int minimumCost(int cost[], int N, int W) 
{ 
       vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
       return helper(cost,N,W,0,dp);
} 
};
// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends