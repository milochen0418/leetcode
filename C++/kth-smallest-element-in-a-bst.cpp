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
    //https://leetcode.com/problems/kth-smallest-element-in-a-bst
    //article https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/3099908/C%2B%2B-DFS-O(N)-9-lines
public:
    int kthSmallest(TreeNode* root, int k) {
        int idx = k, ans = -1;
        function<void(TreeNode*)> dfs =[&](TreeNode* root){
            if(!root) return;
            dfs(root->left);
            if(1==idx--) ans=root->val;
            dfs(root->right);
        } ;
        dfs(root);
        return ans;
    }

    priority_queue<int> maxQ; 
    int size_k = 0;
    int kthSmallest_v01(TreeNode* root, int k) {
        size_k = k;
        travelBST(root);
        return maxQ.top();
    }
    
    void travelBST(TreeNode* root) {
        if(root == nullptr) return;    
        travelBST(root->left);
        maxQ.push(root->val);
        if (maxQ.size()>size_k) {
           maxQ.pop(); 
        }
        travelBST(root->right);
    }
};