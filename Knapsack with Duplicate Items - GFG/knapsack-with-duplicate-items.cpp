// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1002][1002];
    Solution(){memset(dp,-1,sizeof(dp));}
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(W==0||N==0)return 0;
        if(dp[N][W]!=-1)return dp[N][W];
        if(W>=wt[N-1])
        return dp[N][W]=max(val[N-1]+knapSack(N,W-wt[N-1],val,wt),knapSack(N-1,W,val,wt));
        else return dp[N][W]=knapSack(N-1,W,val,wt);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends