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
    //https://leetcode.com/problems/cousins-in-binary-tree
    //article https://leetcode.com/problems/cousins-in-binary-tree/discuss/3055070/C%2B%2B-BFS-O(N)
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> currQ, nextQ;
        currQ.push(root);
        vector<int> w1 = {x,y};
        vector<int> w2 = {y,x};
        bool findX=false, findY=false;
        while(!currQ.empty()) {
            TreeNode* e = currQ.front();
            currQ.pop();
            
            //return false if find x,y have the same parent.
            if(e->left && e->right) {
                vector v = {e->left->val, e->right->val};
                if(w1==v || w2 ==v) return false;    
            }
            if(e->val == x) findX=true;
            if(e->val == y) findY=true;
            
            if (e->left) nextQ.push( e->left);
            if(e->right) nextQ.push(e->right);
            if(currQ.empty()) {
                if(findX ==true && findY==true) return true;
                findX=findY=false;
                swap(currQ,nextQ);
            }
        }
        return false;
    }
};