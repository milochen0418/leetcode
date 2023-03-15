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
    //https://leetcode.com/problems/check-completeness-of-a-binary-tree
public:
    bool isCompleteTree(TreeNode* root) {
        int finished=0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode* e=Q.front();Q.pop();
            if(e->left || e->right) {
                if(!e->left) return false;
                if(finished) return false;
                if(!e->right) finished = 1;
            } else {
                finished = 1;
            }
            if(e->left ) Q.push(e->left );
            if(e->right) Q.push(e->right);
        }
        return true;
    }
};