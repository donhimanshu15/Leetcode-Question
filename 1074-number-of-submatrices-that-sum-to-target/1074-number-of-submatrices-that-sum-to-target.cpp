class Solution {
public:
   
    unordered_map<int,int> map;
   int solve(vector<int>& nums, int target)                         
    { int res=0;
        int sum=0;
        map.clear();
        map[0]++;
        for(int i:nums)
        {
            sum+=i;
            res+=map[sum-target];      
            map[sum]++;                    
        }
     return res;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int ans=0;
        
        for(int i=0;i<matrix.size();i++)                    
        {
            vector<int> row(matrix[0].size());                
            for(int j=i;j<matrix.size();j++)
            {
                for(int k=0;k<matrix[0].size();k++)         
                    row[k]+=matrix[j][k];
                ans+=solve(row,target);
            }
        }
        return ans;
    }
};