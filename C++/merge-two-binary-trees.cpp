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
    //https://leetcode.com/problems/merge-two-binary-trees
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {        
        function<TreeNode*(TreeNode*,TreeNode*)> dfs=[&](TreeNode* r1, TreeNode* r2) {
            if(!r1 && !r2) return (TreeNode*) nullptr;
            return new TreeNode(
                (r1?r1->val:0) + (r2?r2->val:0), 
                dfs(r1?r1->left:nullptr, r2?r2->left : nullptr),
                dfs(r1?r1->right:nullptr, r2?r2->right:nullptr)
            );
        };
        return dfs(root1,root2);
    }
};