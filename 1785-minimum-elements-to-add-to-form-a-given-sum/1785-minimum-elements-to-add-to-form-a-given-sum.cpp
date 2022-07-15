class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        long target = goal - sum;
        return target % limit == 0 ? abs(target / limit) : abs(target/limit) + 1;
    }
};