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
    //https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
    //https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/3227098/C%2B%2B-recursion-by-the-number-of-node-in-subtree
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
        111102222 I (inorder)
        111122220 P (postorder)
        */
        
        int n = inorder.size();
        unordered_map<int,int> mp;//find the index of val in inorder
        for(int i = 0; i<n;i++) mp[inorder[i]] = i;
        function<TreeNode*(int,int,int,int)> build = [&](int Pi, int Pj, int Ii, int Ij) {
            int val = postorder[Pj];
            TreeNode* node = new TreeNode(val);
            int Im = mp[val];
            int LW = Im-Ii;//width of left subtree;
            int RW = Ij-Im;//width of right subtree;
            if(LW>0) node->left = build(Pi, Pi+LW-1, Ii, Im-1);
            if(RW>0) node->right = build(Pi+LW, Pj-1, Im+1, Ij);
            return node;
        };
        TreeNode* t = build(0,n-1,0,n-1);
        return t;
    }
};