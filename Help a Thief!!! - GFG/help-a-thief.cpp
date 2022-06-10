// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool static comp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first > p2.first);
} 

    int maxCoins(int A[], int B[], int T, int N) {
     if(T == 0)return 0;

    vector<pair<int, int >> vi;
    for(int i=0; i<N; i++)
    {
        vi.push_back(make_pair(B[i], A[i]));
    }

    sort(vi.begin(), vi.end(),comp);

    int ans = 0;
    for(int i=0; i<N; i++)
    {
        while(T > 0 and vi[i].second > 0)
        {
            ans = ans + vi[i].first;
            T--;
            vi[i].second--;
        }
    }

    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends