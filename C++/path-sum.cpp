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
        function<bool(TreeNode*, int)> has_path_sum = [&](TreeNode* root, int t){
            if(!root) return false;
            int new_t=t-root->val;
            if(!root->left && !root->right) //leaf
                return new_t==0;
            else
                return has_path_sum(root->left, new_t) || has_path_sum(root->right, new_t);
        };
        return has_path_sum(head,t);
    }

    bool hasPathSum_v01(TreeNode* head, int t) {
        if(!head) return false;
        if(!head->left && !head->right) return t==head->val;
        return hasPathSum(head->left, t-head->val) || hasPathSum(head->right, t-head->val);
    }
};