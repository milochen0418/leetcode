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
        
        while(!qs[qidx].empty()) {
            TreeNode* p = qs[qidx].front();
            qs[qidx].pop();
            TreeNode* childs[] = {p->left, p->right};
            for( auto c: childs) {
                if(c==nullptr) continue;
                qs[(qidx + 1) % 2].push(c);
            }
            
            if(qs[qidx].empty()) {
                qidx=(qidx+1)%2;
                //step++;
                max_width = max(max_width, (int)qs[qidx].size());
            }            
        }
        return max_width;

    }
    
    
};