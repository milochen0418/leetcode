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
    //https://leetcode.com/problems/minimum-depth-of-binary-tree
    //article https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/2310066/C%2B%2B-or-DFS-with-3-lines
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }
    int dfs(TreeNode* root) {
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return 1;
        return 1+min(dfs(root->left), dfs(root->right));
    }
};