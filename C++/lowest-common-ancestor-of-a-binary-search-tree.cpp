/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    //https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
    //article https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/discuss/2256920/C%2B%2B-or-Space-O(1)-Time-O(N)-or-some-new-idea-or-explanation
public:
    TreeNode* smallNode = nullptr;
    TreeNode* largeNode = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Case 1: one is the ancestor to another.
        TreeNode* node;
        int pval = p->val;
        int qval = q->val;
		//Case 1.1: If q is ancestor of p, then in the traveeling of finding p-> val, you can meet q  earilier. 
        node = root;
        while(node->val != pval) {
            if(node == q) return q;
            if(pval < node->val)
                node=node->left;
            else 
                node=node->right;
        }
		//Case 1.2: If p is ancestor of q, then in the travelling of finding q->val, you can meet p earilier. 
        node = root;
        while(node->val != qval) {
            if(node == p) return p;
            if(qval<node->val)
                node=node->left;
            else
                node=node->right;
        }
        
        //Case 2: no one is the ancestor to another.
        if(p->val == q->val) return p;  
        if(p->val<q->val) {
            smallNode = p;
            largeNode = q;
        } else {
            smallNode = q;
            largeNode = p;
        }
        while(smallNode->right!=nullptr) {
            smallNode = smallNode->right;
        }
        while(largeNode->left!= nullptr) {
            largeNode = largeNode->left;
        }
        //Start to find value int the bound (begin,end)  in BST
        int begin = smallNode->val;
        int end = largeNode->val;
        while(!(begin<root->val && root->val<end)) {
            if(root->val > end) 
                root=root->left;
            else 
                root=root->right;
        }
        return root;
    }
};