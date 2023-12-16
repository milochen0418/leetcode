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
    //https://leetcode.com/problems/delete-leaves-with-a-given-value
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) -> TreeNode* {
            if(!root)return root;
            root->left = dfs(root->left);
            root->right = dfs(root->right);            
            return (!root->left && !root->right && root->val==target)?nullptr:root;
        };
        return dfs(root);
    }
};