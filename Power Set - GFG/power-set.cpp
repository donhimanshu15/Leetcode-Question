// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<string> ans;
	void solve(string str, string s ,int i){
	    if(i==s.length() ){
	        if(str!="")
	       ans.push_back(str);
	       return;
	    }
	    
	    solve( str+s[i], s,i+1);
	    solve( str, s,i+1);
	    
	    
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string str = "";
		    solve(str,s,0);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends