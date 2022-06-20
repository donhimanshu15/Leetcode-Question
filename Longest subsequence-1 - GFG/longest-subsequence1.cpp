// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1001][1001];
int solve(int idx,int num,int N, int A[]){
    if(N==idx) return 0;
    if(dp[idx][num]!=-1) return dp[idx][num];
    if(num==A[idx]){
        return dp[idx][num]=1+max(solve(idx+1,A[idx]+1,N,A),solve(idx+1,A[idx]-1,N,A));
    }
    else{
        return dp[idx][num]=solve(idx+1,num,N,A);
    }
    return dp[idx][num];
}
    int longestSubsequence(int N, int A[])
    {
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<N;i++){
            ans= max(ans,solve(i,A[i],N,A));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends