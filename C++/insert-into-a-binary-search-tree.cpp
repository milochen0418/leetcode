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
    //https://leetcode.com/problems/insert-into-a-binary-search-tree
    //article https://leetcode.com/problems/insert-into-a-binary-search-tree/discuss/2402988/C%2B%2B-or-4-lines-iterative-approach
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*& ans = root, **p = &root;
        while((*p)!=nullptr) p = (*p)->val>val ? &(*p)->left:&(*p)->right;
        *p = new TreeNode(val);
        return ans;
    }
};