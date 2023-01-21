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
    //https://leetcode.com/problems/second-minimum-node-in-a-binary-tree
public:
    int findSecondMinimumValue(TreeNode* root) {
        int val = root->val;
        int ans = 0;
        function<void(TreeNode*)> dfs=[&](TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            dfs(root->right);
            if(root->val>val) {
                if(ans==0)ans=INT_MAX;
                ans = min(ans,root->val);
            }
        };
        dfs(root);
        return ans==0?-1:ans;
    }
};