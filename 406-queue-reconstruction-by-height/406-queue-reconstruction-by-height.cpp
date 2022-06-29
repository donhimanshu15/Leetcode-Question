class Solution {
public:
    static bool cmp(vector<int> & P1, vector<int> &P2){
        if(P1[0]!=P2[0]){
            return P1[0]>P2[0];
        }
        return P1[1]<P2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(),people.end(),cmp);
        res.push_back(people[0]);
        for(int i=1;i<people.size();i++){
            int index=people[i][1];
            res.insert(res.begin()+index,people[i]);
        }
        return res;
        
    }
};