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
        
        queue<TreeNode*> qs[2]; 
        int qidx = 0;
        qs[0] = queue<TreeNode*>();
        qs[1] = queue<TreeNode*>();
        
        if(u==root) return nullptr;
        
        qs[qidx].push(root);
        bool startToGetNextNode  = false;
        int step = 0;
        int saved_step = -1;
        
        while(!qs[qidx].empty()) {
            int nidx = (qidx + 1) % 2;
            TreeNode* p = qs[qidx].front();
            qs[qidx].pop();
            
            TreeNode* childs[] = {p->left, p->right};
            for(int i=0; i<2; i++) {
                TreeNode*c = childs[i];
                if(c!=nullptr) {
                    if(startToGetNextNode==true) {
                        if(saved_step == step) {
                            return c;
                        } else {
                            return nullptr;
                        }
                    } else {
                        if(c == u) {
                            saved_step = step;
                            startToGetNextNode = true; 
                        }
                    }
                    qs[nidx].push(c);                    
                }
            }
            
            if(qs[qidx].empty()) {
                qidx=(qidx+1)%2;
                step++;
            }
        }   
        return nullptr;
    }
};