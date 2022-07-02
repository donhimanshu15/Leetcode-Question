class Solution {
public:
    int mod =1000000007;
    long long int L=1;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        vector<int> a;
        vector<int> b;
        a.push_back(0);
        b.push_back(0);
        for(int i=0;i<horizontalCuts.size();i++){
            a.push_back(horizontalCuts[i]);
        }
           for(int i=0;i<verticalCuts.size();i++){
            b.push_back(verticalCuts[i]);
        }
        a.push_back(h);
        b.push_back(w);
        sort(a.begin(),a.end());
         sort(b.begin(),b.end());
        int row=INT_MIN;
        int col=INT_MIN;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]>row) row=a[i]-a[i-1];
        }
         for(int i=1;i<b.size();i++){
            if(b[i]-b[i-1]>col) col=b[i]-b[i-1];
        }
        return (L*(col%mod)*(row%mod))%mod;
    }
};