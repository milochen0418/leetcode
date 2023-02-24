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
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
          preorder [Pi.. Pj] and inorder [Ii.. Ij] can build a tree
          Case no empty child 
          P=011112222
          I=111102222
          Case left child is null
          P=02222
          I=02222
          Case right child is null
          P=01111
          I=11110
        */
        
        function<TreeNode*(int,int,int,int)> build = [&](int Pi, int Pj, int Ii, int Ij) {
            int val = preorder[Pi];
            TreeNode* node = new TreeNode(val);
            if(Pi==Pj) return node;
            int Im;
            for(Im = Ii; Im<=Ij;Im++) if(inorder[Im] == val) break;
            int LW = Im-Ii;//width of left subtree (the number of node for left  subtree)
            int RW = Ij-Im;//width of right subtree(the number of node for right subtree)
            if(LW>0) node->left = build(Pi+1, Pi+LW, Ii, Im-1);
            if(RW>0) node->right = build(Pi+LW+1,Pj, Im+1,Ij );
            return node;
        };
        int n = preorder.size();
        TreeNode* t = build(0,n-1, 0, n-1);
        return t;
    }
};