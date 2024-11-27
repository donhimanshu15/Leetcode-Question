class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0);
        for(auto& edge: edges){
            int weakerTeam = edge[1];
            inDegree[weakerTeam]++;
        }

        vector<int> noIncomingEdges;
        for(int i = 0; i < n; i++){
            if (inDegree[i] == 0)
                noIncomingEdges.push_back(i);
        }

        if (noIncomingEdges.size() != 1) return -1;
        else return noIncomingEdges[0];
    }
};