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
    //https://leetcode.com/problems/maximum-width-of-binary-tree/
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> qs[2] = {queue<TreeNode*>(), queue<TreeNode*>()};
        int qidx = 0;
        qs[qidx].push(root);
        int max_width = 1;
        
        
        int x = 0;
        int x_begin = -1;
        int x_end = -1;
        
        while(!qs[qidx].empty()) {
            TreeNode* p = qs[qidx].front();
            qs[qidx].pop();
            if(p == nullptr) continue;
            TreeNode* childs[] = {p->left, p->right};
            for( auto c: childs) {    
                qs[(qidx + 1) % 2].push(c);
                if(x_begin == -1) {
                    if(c!=nullptr) {
                        x_begin = x;    
                        x_end = x;
                    }
                } else {//x_begin ha
                    if(c!=nullptr) {
                        x_end = x;
                    }
                }
                x++;
            }
            
            if(qs[qidx].empty()) {
                
                if(x_begin != -1) {
                    max_width = max(max_width, x_end-x_begin+1);
                }
                x = 0;
                x_begin=-1;
                x_end=-1;
                qidx=(qidx+1)%2;
            }            
        }
        return max_width;

    }
    
    
};

/* testcase
[1,3,2,5,3,null,9]
[1,3,null,5,3]
[1,3,2,5]

*/
