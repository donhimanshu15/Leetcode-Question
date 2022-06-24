// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        int n = a.size();
        sort(a.begin(), a.end());
        
        int l=0, r=0, maxlen=0;
        
        while(r<n){
            if(a[r]-a[l] <= k){
                r++;
                maxlen = max(maxlen, r-l);
            }
            else{
                l++;
            }
        }
        
        return n-maxlen;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends