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
    //https://leetcode.com/problems/minimum-distance-between-bst-nodes/
public:
    int ans=INT_MAX;
    int prev_v=INT_MAX;
    
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        ans = min(ans, abs(prev_v-root->val));
        prev_v = root->val;
        dfs(root->right);
    }
};