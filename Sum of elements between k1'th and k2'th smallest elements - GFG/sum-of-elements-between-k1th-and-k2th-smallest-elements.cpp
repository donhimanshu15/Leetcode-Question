// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
  long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        int i = 1;
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq (A, A + N);
        while(pq.empty() == false && i < K2){
            if(i > K1 && i < K2){
                sum += pq.top();
            }
            i++;
            pq.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends