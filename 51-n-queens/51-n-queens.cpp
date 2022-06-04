class Solution {
public:
    bool isValid(int n,int row, int col,vector<string> &res)
    {
     if(row>=n || col>=n|| col<0|| row<0) return false;
     for(int i=col;i>=0;i--){
         if(res[row][i]=='Q') return false;
     }
        for(int i=row, j=col;i>=0 && j>=0;j--,i--){
            if(res[i][j]=='Q') return false;
            
        }
        for(int i=row, j=col;i<n && j>=0; j--,i++){
            if(res[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(int n, int col,  vector<string> &res,  vector<vector<string>> &ans){
        if(n==col){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(n,i,col,res)){
            res[i][col]='Q';
                solve(n,col+1,res,ans);
                res[i][col]='.';
              
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n,string(n,'.'));
        solve(n,0,res, ans);
        return ans;
    }
};