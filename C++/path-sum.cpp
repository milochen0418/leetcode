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
    //https://leetcode.com/problems/path-sum
    //article https://leetcode.com/problems/path-sum/discuss/2310019/C%2B%2B-or-Recursive-3-lines
public:
    bool hasPathSum(TreeNode* head, int t) {
        if(!head) return false;
        if(!head->left && !head->right) return t==head->val;
        return hasPathSum(head->left, t-head->val) || hasPathSum(head->right, t-head->val);
    }
};