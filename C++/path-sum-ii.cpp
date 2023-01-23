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
    //https://leetcode.com/problems/path-sum-ii
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> stk;
        function<void(TreeNode*,int)> path_sum = [&](TreeNode *root, int t){
            if(!root) return;
            int new_t = t - root->val;
            stk.push_back(root->val);
            if(!root->left && !root->right) {//if root is leaf
                if(new_t==0) ans.push_back(stk);
            } else {
                path_sum(root->left, new_t);
                path_sum(root->right, new_t);
            }
            stk.pop_back();
        };
        path_sum(root, targetSum);
        return ans;
        
    }
};