// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    { int cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int si=mp.size();
        mp.clear();
        int i=0;int j=0;
         int ans = 0;
       while(j < n){
           if(mp[arr[j]] == 0) cnt++;
           mp[arr[j]]++;
           
           while(cnt == si){
               ans += n-j;
               
               mp[arr[i]]--;
               if(mp[arr[i]] == 0) cnt--;
               i++;
           }
                 j++;
       }
        return ans;
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
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends