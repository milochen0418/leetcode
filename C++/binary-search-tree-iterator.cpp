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
class BSTIterator {
    //https://leetcode.com/problems/binary-search-tree-iterator
public:
    stack<TreeNode*> stk;

    BSTIterator(TreeNode *root) {
        while(root!=nullptr) {
            stk.push(root);
            root = root->left;
        }
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
    int next() {
        TreeNode *root = stk.top();
        stk.pop();
        TreeNode *root_right = root->right;
        while(root_right!=nullptr) {
            stk.push(root_right);
            root_right = root_right->left;
        }
        return root->val;
    }
    
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */