/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL ) return;
        map<int,int> m;
        queue<TreeNode*> q;
        q.push(root);
          int level=0;
        m[level]=root->val;
        while(!q.empty()){
          level++;
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* cur=q.front();
                if(!q.empty()) q.pop();
                if(cur->left!=NULL) {
                    q.push(cur->left);
                    
                   m[level]=cur->left->val;
                }
                if(cur->right) {q.push(cur->right);
                                 m[level]=cur->right->val;}
        }
           
            }
         for(int i=0;i<level;i++){
                ans.push_back(m[i]);}
    }
    vector<int> rightSideView(TreeNode* root) {
        
     vector<int> ans;
        if(root==NULL) return ans;
        solve(root, ans);
            return ans;
    }
};