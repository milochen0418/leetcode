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
    //https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers
public:
    int ans = 0;
    int sumRootToLeaf(TreeNode* root) {
        dfs(0, root);
        return ans;
    }
    void dfs(int val, TreeNode* root) {
        if(!root)return;
        val<<=1;
        if(root->val) val|=1;
        if(!root->left && !root->right) ans+=val;
        dfs(val, root->left);
        dfs(val, root->right);
    }
    
};