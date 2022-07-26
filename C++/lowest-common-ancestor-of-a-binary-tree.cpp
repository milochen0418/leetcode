/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    //https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
public:
    vector<TreeNode*> pv;
    vector<TreeNode*> qv;
    vector<TreeNode*> tmp;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q); //find out pv and qv by one DFS. 
        int n = min(pv.size(), qv.size());
        TreeNode* ans=nullptr;
		//Find out the last same element in pv and qv
        for(int i = 0; i<n;i++) {
            if(pv[i]!=qv[i]) break;
            ans = pv[i];
        }
        return ans;
    }
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return;
        tmp.push_back(root);
        if(root==p) pv = tmp;
        if(root==q) qv = tmp;
        dfs(root->left, p, q);
        dfs(root->right,p, q);
        tmp.pop_back();
    }
};