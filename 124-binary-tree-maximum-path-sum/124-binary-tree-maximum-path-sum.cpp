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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
         int left= max(0,solve(root->left));
        int right= max(0,solve(root->right));
        int sum= root->val+right+left;
        ans=max(ans,sum);
       return root->val+max(right,left);
    }
    int maxPathSum(TreeNode* root) {
       solve(root);
        return ans;
    }
};