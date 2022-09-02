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
    int cnt=0;
  void solve(int maxi, TreeNode* root){
      if(root==NULL) return ;
        if(maxi<=root->val) cnt++;
        solve(max(maxi,root->val), root->left);
        solve(max(maxi,root->val), root->right);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        solve(INT_MIN,root);
        return cnt;
    }
};