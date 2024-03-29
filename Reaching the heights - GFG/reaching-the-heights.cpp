// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
   sort(a,a+n);
   vector<int> ans;
    vector<char> ans1;
   int i=0;
   int j=n-1;
   int sum=0;
   while(i<=j){
       if(i==j){ ans.push_back(a[i]); 
      if(i%2!=0) sum+=a[i]; 
       
      else sum-=a[i];
       break;}
       ans.push_back(a[j]); 
       sum+=a[j];
       ans.push_back(a[i]);
       sum-=a[i];
       j--;
       i++;
   }
   
  if(sum==0) return {-1};
  else return ans;
}
