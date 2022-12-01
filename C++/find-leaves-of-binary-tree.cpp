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
    //https://leetcode.com/problems/find-leaves-of-binary-tree/
    //article https://leetcode.com/problems/find-leaves-of-binary-tree/discuss/2866657/C%2B%2B-or-DFS-or-easy
public:
    vector<vector<int>> ans;
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;        
    }
    int dfs(TreeNode* root) {
        if(!root) return -1;
        int h = 1 + max(dfs(root->left), dfs(root->right));
        if(h>=ans.size()) ans.push_back(vector<int>());
        ans[h].push_back(root->val);
        return h;
    }
};