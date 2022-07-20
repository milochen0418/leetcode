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
    //https://leetcode.com/problems/sum-of-left-leaves
public:
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* dummy = new TreeNode();
        dummy->right = root;
        return dfs(dummy,root);
    }
    int dfs(TreeNode* parent, TreeNode *head) {
        if(head == nullptr) return 0;
        if(head->left ==nullptr && head->right == nullptr) {
            return (parent->left == head)?head->val:0;
        } 
        return dfs(head, head->left) + dfs(head, head->right);
    }
};