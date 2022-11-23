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
    //https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> A;
        A.push_back(INT_MIN);
        inorder(root,A);
        A.push_back(INT_MAX);
        
        int n = A.size(), m = queries.size();
        vector<vector<int>> qs = vector<vector<int>> (m, vector<int>(4,-1));
        for(int i = 0; i < queries.size(); i++) {
            qs[i][0] = queries[i];
            qs[i][1] = i;
        }
        
        sort(qs.begin(), qs.end(), [](auto &lhs, auto &rhs){return lhs[0] < rhs[0];});
        
        int Ai = 0, Qi =0; //Ai is index of A, Qi is index of qs
        while(Ai < n && Qi < m) {
            if(qs[Qi][0] == A[Ai]){
                qs[Qi][2] = qs[Qi][3] = qs[Qi][0];
                Qi++;
            } else if(qs[Qi][0] > A[Ai]) {
                Ai++;
            } else { //case (qs[Qi][0]<  A[Ai]) 
                if(Ai-1>0) qs[Qi][2] = A[Ai-1];
                if(Ai<n-1) qs[Qi][3] = A[Ai];
                Qi++;
            }           
        }
        
        sort(qs.begin(), qs.end(), [](auto &lhs, auto&rhs){return lhs[1] < rhs[1];});
        
        for(auto &v: qs) {
            ans.push_back({v[2], v[3]});
        }
        return ans;
    }
    
    void inorder(TreeNode* root, vector<int>& res) {
        if(root==nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }  
};