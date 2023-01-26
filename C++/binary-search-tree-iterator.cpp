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
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }

    bool hasNext() {
        return !stk.empty();
    }

    int next() {
        TreeNode *node = stk.top();
        stk.pop();
        int ret = node->val;
        node=node->right;
        while(node) {
            stk.push(node);
            node=node->left;
        }
        return ret;
    }
    
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */