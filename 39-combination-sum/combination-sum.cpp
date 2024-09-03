class Solution {
public:
vector<vector<int>>  ans;
vector<int> res;
     void solve(vector<int>& candidates, int target, int idx){
        if(idx>0 && candidates[idx]== candidates[idx-1]) return;
        if(target == 0) {ans.push_back(res); return;}
        if(idx == candidates.size()  ) return;
        for(int i=idx;i<candidates.size();i++){
            if(target>= candidates[i] ){res.push_back(candidates[i]);
            solve(candidates, target-candidates[i],i);
            res.pop_back();
            }
            else break;
        }
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates, target,0);
        return ans;
    }
};