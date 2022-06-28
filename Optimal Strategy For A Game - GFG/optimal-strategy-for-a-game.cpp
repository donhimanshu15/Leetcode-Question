// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
   
    public:
   long long int solve(int i,int j, int nums[],vector<vector<long long int >> &dp ){
         if(i==j)
        {
            return nums[i];
        }
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long int  choice1=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
       long long  int choice2=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        dp[i][j]=max(choice1,choice2);
        return dp[i][j];
   }
    long long maximumAmount(int nums[], int n){
        
     vector<vector<long long int>> dp (n+1,vector<long long int>(n+1,-1));
     return solve(0,n-1,nums,dp);
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends