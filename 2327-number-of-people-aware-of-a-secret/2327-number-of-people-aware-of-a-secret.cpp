class Solution {
public:
    int mod= 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> know(2500,0);
        know[1]=1;
        for(int i=1;i<=n;i++){
            for(int to=i+delay;to<i+forget;to++){
                know[to]=(know[to]+know[i])%mod;
            }
        }
        int ans=0;
        for(int j=max(1,n-forget+1);j<=n;j++){
            ans=(ans+know[j])%mod;
        }
        return ans;
    }
};