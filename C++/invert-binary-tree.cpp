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
    //https://leetcode.com/problems/invert-binary-tree
    //article https://leetcode.com/problems/invert-binary-tree/discuss/2313784/C%2B%2B-or-2-lines-solution-or-DFS
public:
    TreeNode*& invertTree(TreeNode*& root) {
        if(root) swap(invertTree(root->left), invertTree(root->right));
        return root;
    }
    TreeNode* invertTreeVer01(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        swap(root->left, root->right);
        dfs(root->left);
        dfs(root->right);        
    }
};