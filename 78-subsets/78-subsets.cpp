class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return res;
    }
    void solve(vector<int>& nums, int i){
        res.push_back(path);
        if(i >= nums.size()) return;
        for(int j = i; j < nums.size(); ++j){
            path.push_back(nums[j]);
            solve(nums, j + 1);
            path.pop_back();
        }
    }
};