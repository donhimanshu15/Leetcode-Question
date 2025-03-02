class Solution {
public:
    int totalFruit(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0);  // ⚡ Fast I/O
        int i = 0, ans = 0;  // i = left pointer, ans = max fruits collected
        unordered_map<int, int> mp;  // \U0001f34f Store fruit type counts
        
        for (int j = 0; j < nums.size(); j++) {  // j = right pointer extending the window
            mp[nums[j]]++;  // \U0001f34a Add the current fruit to the window
            
            while (mp.size() > 2) {  // ❌ More than 2 types? Shrink window
                if (--mp[nums[i]] == 0) mp.erase(nums[i]);  // Remove leftmost fruit if count reaches 0
                i++;  // Move left pointer \U0001f343
            }
            
            ans = max(ans, j - i + 1);  // ✅ Update max length of valid window
        }
        
        return ans;  // \U0001f3af Return the maximum number of fruits collected
    }
};
