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
    //https://leetcode.com/problems/two-sum-iv-input-is-a-bst
public:
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        dfs1(root);
        for(auto &i:s) if(s.find(k-i) != s.end() && i!=k-i) return true;
        return false;
    }
    void dfs1(TreeNode* root) {
        if(!root) return;
        s.insert(root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    
};