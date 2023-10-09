/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
    //https://leetcode.com/problems/extract-kth-character-from-the-rope-tree
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        while(root->len!=0) {
            if(root->left == NULL) {
                root=root->right;
            } else if(k>get_len(root->left)) {
                k-=get_len(root->left);
                root=root->right;
            } else {
                root=root->left;
            }
        }
        return root->val[k-1];
    }
    int get_len(RopeTreeNode* node) {
        return node->len?node->len:(node->val).length();
    }
};