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
    //https://leetcode.com/problems/binary-tree-level-order-traversal/
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        if(root ==nullptr )return ans;
        queue<TreeNode*> currQ;
        queue<TreeNode*> nextQ;
        currQ.push(root);
        ans.push_back(vector<int>());
        while(!currQ.empty()) {    
            TreeNode* e =currQ.front();
            ans.back().push_back(e->val);
            currQ.pop();
            for(auto c: {e->left, e->right}) if(c!=nullptr) nextQ.push(c);
            if(currQ.empty()) {
                swap(currQ,nextQ);
                if(!currQ.empty())ans.push_back(vector<int>());
            }
        }
        return ans;
    }
};