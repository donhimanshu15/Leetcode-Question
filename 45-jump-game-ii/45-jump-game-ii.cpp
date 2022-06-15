class Solution {
public:
    int t[10001];
    int minSteps(int i, vector<int> &nums) {
        int n = nums.size();
        if(i >= n-1){
            return 0;
        }
        if(t[i] != 10006)
            return t[i];
        for(int j=1; j<=nums[i]; j++) {
            t[i] = min(t[i], 1 + minSteps(i+j, nums));
        }
        return t[i];
    }


    int jump(vector<int>& nums) {
        for(int &i: t) {
            i = 10006; // assume as INT_MAX
        }
        int res = minSteps(0, nums);
        return res;
    }
};