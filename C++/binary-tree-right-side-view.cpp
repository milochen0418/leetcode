/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };,
 */
class Solution {
    //https://leetcode.com/problems/binary-tree-right-side-view/
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> currQ, nextQ;
        if(!root) return ans;
        int last_val = root->val;
        currQ.push(root);
        while(!currQ.empty()) {
            TreeNode* e = currQ.front();
            currQ.pop();
            last_val = e->val;
            if(e->left) nextQ.push(e->left);
            if(e->right) nextQ.push(e->right);
            if(currQ.empty()) {
                ans.push_back(last_val);
                swap(currQ, nextQ);
            }
        }
        return ans;
    }
};