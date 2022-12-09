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
    //https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
    //
public:

    int dfs(TreeNode* root,int maxv,int minv) {
        if(!root) return (maxv - minv);
        maxv = max(maxv,root->val);
        minv = min(root->val, minv);
        return max( dfs(root->left,maxv,minv), dfs(root->right,maxv,minv));
    }

    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return dfs(root,INT_MIN,INT_MAX);
    }
};