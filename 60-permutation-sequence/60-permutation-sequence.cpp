class Solution {
public:
    void solve(vector<int>& v,string& ans,int n,int k,vector<int>& factVal){
        if(n==1){
        ans+=to_string(v.back());
            return;
        }
        int index = (k/factVal[n-1]);
       
		if(k % factVal[n-1] == 0){
            index--;
        }
        ans+= to_string(v[index]);  // add value to string
        v.erase(v.begin() + index);  // remove element from array
        k -= factVal[n-1] * index;   // adjust value of k; k = 15 - 6*2 = 3.
		
       solve(v,ans,n-1,k,factVal);
    }
    string getPermutation(int n, int k) {
        string ans;
        vector<int> v;
        vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        for(int i=1;i<=n;i++) v.push_back(i);
         solve(v,ans,n,k,factVal);
        return ans;
    }
};