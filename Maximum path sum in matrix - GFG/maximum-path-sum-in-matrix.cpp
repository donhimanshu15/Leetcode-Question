// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

int solve(vector<vector<int>> &Matrix, int N, int i, int j, vector<vector<int>> &memo){
    if(i<0 or i>=N or j<0 or j>=N){
        return 0;
    }
    
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    int down = solve(Matrix, N, i+1, j, memo);
    int right = solve(Matrix, N, i+1, j+1, memo);
    int left = solve(Matrix, N, i+1, j-1, memo);
    
    memo[i][j] = Matrix[i][j] + max({ down, right, left });
    return memo[i][j];
}

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> memo(N, vector<int>(N, -1));
        int result = 0;
        
        for(int i=0; i<N; i++){
            result = max(result, solve(Matrix, N, 0, i, memo));
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends