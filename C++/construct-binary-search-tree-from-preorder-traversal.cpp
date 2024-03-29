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
    //https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
    //article https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/2910228/C%2B%2B-or-7-lines-or-easy-or-explanation
public:

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root; 
        for(auto &v:preorder) {
            TreeNode** c = &root;
            while(*c) c = (v>(*c)->val)?&((*c)->right):&((*c)->left);
            *c = new TreeNode(v);
        }
        return root;
    }

    TreeNode* bstFromPreorder_v01(vector<int>& preorder) {
        int n = preorder.size(), i=0;
        TreeNode* root = new TreeNode(preorder[0]);
         
        for(int i = 1; i<n;i++) {
            int val = preorder[i];
            TreeNode *node = root;
            while(node) {
                TreeNode*& child = val>node->val?node->right:node->left;
                if(!child) {
                    child = new TreeNode(val);
                    break;
                } else {
                    node = child;
                }
            }
        }
        return root;
    }
};