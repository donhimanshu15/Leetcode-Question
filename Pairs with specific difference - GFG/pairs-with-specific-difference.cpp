// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
       int sum=0;
       sort(arr,arr+n);
       for(int i=n-1;i>=1;)
       {
           if(arr[i]-arr[i-1]<k)
           {
               sum=arr[i]+arr[i-1]+sum;
               i=i-2;
           }
           else
           i=i-1;
           
       }
       return sum; 
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends