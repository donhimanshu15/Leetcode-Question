class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, mid = INT_MAX;
        for (auto num : nums) {
            if (num < first)
                first = num;
            else if (first < num && num < mid)
                mid = num;
            else if (mid < num)
                return true;
        }
        return false;
    }
};