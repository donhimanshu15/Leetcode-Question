class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        vector<pair<int, int>> all;
        for (int j = 0; j < n; j ++) all.push_back({nums[j], j});
        sort (all.begin(), all.end());
            
        set<int> active;
        for (int j = n-1; j >= 0; j --) {
            int start = j;
            vector<int> indexes_to_activate;
            
            while (j >= 0 && all[j].first == all[start].first) {
                int ind = all[j].second;
                int second_greater_ind = -1;
                
                auto it = active.upper_bound(ind);
                if (it != active.end()) {
                    ++ it;
                    if (it != active.end()) {
                        second_greater_ind = *it;
                    }
                }
                result[ind] = second_greater_ind != -1? nums[second_greater_ind] : -1;
                
                indexes_to_activate.push_back(ind);
                j --;
            }
            j ++;
            
            for (auto i : indexes_to_activate) active.insert(i);
        }
        
        return result;
    }
};