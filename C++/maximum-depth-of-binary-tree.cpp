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
    //https://leetcode.com/problems/maximum-depth-of-binary-tree
    //article https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/1769457/c-dfs-on-one-line
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int len = maxDepth(root->left) + 1;
        len = max(len, maxDepth(root->right)+1) ;
        return len;
    }
    
};