// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
  int dp[100001][4];
  int mod=1e9+7;
    int solve(string &s, string b, int n1, int n2){
        if(dp[n1][n2]!=-1){return dp[n1][n2];}
        if(n2==0) return 1;
        if (n1 == 0)
            return  0;
        
        
        int take=0;
        if(s[n1 - 1] == b[n2 - 1])
       {  take=solve(s,b, n1 - 1, n2 - 1)+solve(s,b, n1 - 1, n2);
       take%=mod;
       
       
      
  
        }
        take+= solve(s,b, n1 - 1, n2);
        return dp[n1][n2]=(take)%mod;
    }
    int fun(string &s) {
    string str="abc";
        memset(dp,-1,sizeof(dp));
        int n1=s.length();
       return solve(s,str,n1, 3);
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends