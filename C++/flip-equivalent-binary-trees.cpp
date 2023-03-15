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
    //https://leetcode.com/problems/flip-equivalent-binary-trees
    //article https://leetcode.com/problems/flip-equivalent-binary-trees/discuss/3298531/C%2B%2B-sort-and-compare-O(N)
public:
    /*
    Observation: Each tree will have unique node values, 
    So we can swap root->left, root->right to make sure that root->left->val < root->right->val. 
    */

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        function<void(TreeNode*)> dfs_sort = [&](TreeNode* root) {
            if(!root) return;
            if(!root->left) {
                swap(root->left,root->right);
            } else if(root->left && root->right) {
                if(root->left->val > root->right->val) 
                    swap(root->left, root->right);
            }
            dfs_sort(root->left);
            dfs_sort(root->right);
        };
        
        function<bool(TreeNode*, TreeNode*)> dfs_same = [&](TreeNode* r1, TreeNode* r2) {
            if( ( (!r1) && r2) || (r1 && (!r2)) ) return false;
            if( (!r1) && (!r2)) return true;
            if(r1->val != r2->val) return false;
            return (dfs_same(r1->left, r2->left) && dfs_same(r1->right, r2->right));
        };
        
        dfs_sort(root1);
        dfs_sort(root2);
        return dfs_same(root1, root2);
    }
};