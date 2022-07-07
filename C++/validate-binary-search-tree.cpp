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
    //https://leetcode.com/problems/validate-binary-search-tree
public:
    int *curr=nullptr;
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
    bool dfs(TreeNode* head) {
        if(head->left !=nullptr) {
            if(!dfs(head->left))return false;
        }
        if(curr != nullptr && *curr >= head->val) 
            return false;
        else 
            curr = &(head->val);
        if(head->right != nullptr) {
            if(!dfs(head->right)) return false;
        }
        return true;
    }
};
/* testcase 
[5,4,6,null,null,3,7]
[2,1,3]
[5,1,4,null,null,3,6]
[-2147483648]
[-2147483648,null,2147483647]
*/