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
    //https://leetcode.com/problems/count-good-nodes-in-binary-tree
    //article https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/3076023/C%2B%2B-Recursive-DFS-with-Stack
public:
    stack<int> stk;
    int ans = 0;
    int goodNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        int need_push = 0;
        if(stk.empty() || root->val >= stk.top()) {
            ans++;
            need_push = 1;
        }
        if(need_push) stk.push(root->val);
        dfs(root->left);
        dfs(root->right);
        if(need_push) stk.pop();
    }
};