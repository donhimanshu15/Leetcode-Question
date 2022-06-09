// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int dp[101][101];

  int solve(string s, string t, int i, int j){
      
       if(i==s.length()) return t.length()-j;
       
       if(j==t.length()) return s.length()-i;
       if(dp[i][j]!=-1) return dp[i][j];
       if(s[i]==t[j]) return dp[i][j]=solve(s,t,i+1,j+1);
       else{
           int rep= 1+ solve(s,t,i+1,j+1);
           int rem= 1+ solve(s,t,i+1,j);
           int ins=1+solve(s,t,i,j+1);
           return dp[i][j]= min(rep,min(rem,ins));
       }
       
  }
  
    int editDistance(string s, string t) {
        
      int n=s.length();
      int m = t.length();
        for(int i=0;i<101;i++){
      for(int j=0;j<101;j++){
          dp[i][j]=-1;
      }
  }
      int ans= solve(s,t,0,0);
      return ans;
       
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends