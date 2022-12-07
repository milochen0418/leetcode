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
    //https://leetcode.com/problems/range-sum-of-bst
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int &rv = root->val;
        return (L<=rv&&rv<=H?rv:0)+(L<rv?rangeSumBST(root->left,L,H):0)+(H>rv?rangeSumBST(root->right,L,H):0);        
    }
};