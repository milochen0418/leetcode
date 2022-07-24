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
    //https://leetcode.com/problems/diameter-of-binary-tree
public:
    unordered_map<TreeNode*, int> mp;//longest path from root to leaf
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
        mp[nullptr] = 0;
        dfs1(root);
        dfs2(root);
        return ans;
    }
    void dfs1(TreeNode* root) {
        if(!root) return;
        dfs1(root->left);
        dfs1(root->right);
        mp[root] = 1+max(mp[root->left], mp[root->right]);
    }
    void dfs2(TreeNode*root) {
        if(!root) return;
        ans = max(ans, mp[root->left] + mp[root->right]);
        dfs2(root->left);
        dfs2(root->right);
    }
};