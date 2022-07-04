// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
       
     int getSetBits(int b)
    {
        int count=0;
        while(b)
        {
            b = b & (b-1);
            count++;
        }
        return count;
    }
    int minVal(int a, int b) {
        // code here
        int setBits = getSetBits(b);
        //cout<<setbits<<"hello\n";<br>
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            bool set = a & mask;
            if (set && setBits > 0) {
                ans |= (1 << i);
                setBits--;
            }
        }

        //cout<<setbits<<"hi\n";<br>
        if(setBits>0)
        {
            for(int i=0;i<32;i++)
            {
                int mask = 1 << i;
                bool set = ans & mask;

                if(!set && setBits)
                {
                    ans|=(1<<i); setBits--; }
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
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends