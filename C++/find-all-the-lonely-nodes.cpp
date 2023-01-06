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
    //https://leetcode.com/problems/find-all-the-lonely-nodes
    //article https://leetcode.com/problems/find-all-the-lonely-nodes/discuss/3009566/C%2B%2B-DFS
public:
    vector<int> ans;
    vector<int>& getLonelyNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        if( (!root->left&&root->right)) ans.push_back(root->right->val);
        if( (root->left&&!root->right)) ans.push_back(root->left ->val);
    }
};