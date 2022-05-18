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
    //https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
    //article https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/discuss/2049589/C%2B%2B-or-simulation-approach-%2B-BFS
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> Q1;
        queue<TreeNode*> Q2;
        Q1.push(original);
        Q2.push(cloned);
        while(!Q1.empty()) {
            TreeNode* e1=Q1.front();
            TreeNode* e2=Q2.front();
            if(e1 == target) return e2;
            Q1.pop();
            Q2.pop();
            for(auto &c:{e1->left, e1->right}){
                if(c!=nullptr) Q1.push(c);
            }
            for(auto &c:{e2->left, e2->right}){
                if(c!=nullptr) Q2.push(c);
            }
        }
        return nullptr;
    }
};