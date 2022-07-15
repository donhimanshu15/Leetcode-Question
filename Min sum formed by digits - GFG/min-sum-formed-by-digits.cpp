// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int a[], int n)
    {
        if(n==1) return a[0];
       sort(a,a+n);
       long long int digit1=a[0];
       long long int digit2=a[1];
       int flag=0;
       for(int i=2;i<n;i++){
           if(flag==0){
               digit1=digit1*10+a[i];
               flag=!flag;
           }
           else{
              digit2=digit2*10+a[i];
               flag=!flag;  
           }
       }
       return digit1+digit2;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends