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
    //https://leetcode.com/problems/same-tree/    
    //article https://leetcode.com/problems/same-tree/discuss/2309873/C%2B%2B-or-DFS-or-4-lines
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==q) return true;
        if(!p != !q) return false; 
        if(p->val!=q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};