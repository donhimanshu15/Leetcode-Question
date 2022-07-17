class Solution {
public:
  
    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        unordered_map<int, priority_queue<int>> mpp;
        for(auto num: nums) {
            mpp[getSum(num)].push(num);
        }
        
        for(auto it: mpp) {
            if(it.second.size() < 2)
                continue;
            int tem = it.second.top();
            it.second.pop();
            tem += it.second.top();
            maxi = max(maxi, tem);
        }
        return maxi;
    }
      int getSum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};