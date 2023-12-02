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
    //https://leetcode.com/problems/binary-tree-pruning/
public:
    TreeNode* pruneTree(TreeNode* root) {
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return 0;
            int L = dfs(root->left);
            int R = dfs(root->right);
            if(L==0) root->left = NULL;
            if(R==0) root->right = NULL;
            return (root->val+L+R) >=1?1:0;
        };
        int v = dfs(root);
        return v==1?root:NULL;
    }
};