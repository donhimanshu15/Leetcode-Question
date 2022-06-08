class Solution {
public:
  bool  equalSubset(int N, vector<int> &arr, vector<vector<int>> & dp, int sum){
    if(sum==0)return 1;
    if(N==0&& sum!=0) return 0;
    if(dp[N][sum]!=-1) return dp[N][sum];
    if(arr[N-1]>sum) return equalSubset(N-1,arr,dp,sum);
    return dp[N][sum]= equalSubset(N-1,arr,dp,sum)|| equalSubset(N-1,arr,dp,sum-arr[N-1]);
    
}
    bool canPartition(vector<int>& arr) {
         int sum =0;
        int N= arr.size();
        for(int i=0; i<N; i++){
            sum+= arr[i];
        }
        if (sum%2!=0) return 0;
    vector<vector<int> > dp(N + 1,
                            vector<int>(sum + 1, -1));
    return equalSubset(N, arr, dp , sum/2);
    }
};