class Solution {
public:
 static bool sortcall( vector<int> &v1, vector<int> &v2){
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortcall);
        int i=0,ans=0;
        while(i<boxTypes.size() and truckSize>0)
        {
            if(boxTypes[i][0]<=truckSize){
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize=truckSize-boxTypes[i][0];
            }
            else if(boxTypes[i][0]>truckSize){
                ans += truckSize*boxTypes[i][1];
                truckSize=0;
            }
            i++;
        }
        return ans;
    }
};