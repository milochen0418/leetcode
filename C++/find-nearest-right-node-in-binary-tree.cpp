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
    //https://leetcode.com/problems/find-nearest-right-node-in-binary-tree
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(u==root) return nullptr;
        queue<TreeNode*> qs[2] = {queue<TreeNode*>(), queue<TreeNode*>()};
        int qidx = 0;
        qs[qidx].push(root);
        
        bool startToGetNextNode  = false;
        int step = 0;
        int saved_step = -1;
        
        while(!qs[qidx].empty()) {
            TreeNode* p = qs[qidx].front();
            qs[qidx].pop();
            TreeNode* childs[] = {p->left, p->right};
            for( auto c: childs) {
                if(c==nullptr) continue;                
                if(startToGetNextNode==true) {
                    return saved_step == step ? c : nullptr;
                } else if(c == u) { 
                    saved_step = step;
                    startToGetNextNode = true;                     
                }
                qs[(qidx + 1) % 2].push(c);
            }
            
            if(qs[qidx].empty()) {
                qidx=(qidx+1)%2;
                step++;
            }
        }   
        return nullptr;
    }
};