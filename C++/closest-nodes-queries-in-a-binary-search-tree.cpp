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
    //https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
public:
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> A;
        A.push_back(INT_MIN);
        inorder(root,A);
        A.push_back(INT_MAX);
        //printf("\nA = ");
        //for(auto &i:A) printf("%d, ", i);
        vector<vector<int>> qs = vector<vector<int>> (queries.size(), vector<int>());
        for(int i = 0; i < queries.size(); i++) {
            qs[i].push_back( queries[i]); //quries value
            qs[i].push_back(i);//index
            qs[i].push_back(-1);//min_i
            qs[i].push_back(-1);//max_i
        }
        
        sort(qs.begin(), qs.end(), [](auto &lhs, auto &rhs){
           return lhs[0] < rhs[1];
        });
        int n = A.size(), m = queries.size();
        int Ai = 0, Qi =0;
        printf("A[] = ");
        for(auto &i: A) printf("%d, ", i);
        printf("\n");
        printf("qs[][0] = ");
        for(auto &q: qs) printf("%d, ", q[0]);
        printf("\n");
        
        while(Ai < n && Qi < m) {
            printf("(Qi,Ai)=(%d, %d) Q[][0]=%d, A[]=%d\n", Qi,Ai, qs[Qi][0], A[Ai]);
            if(qs[Qi][0] < A[1]) {
                qs[Qi][2] = -1;
                qs[Qi][3] = A[1]; 
                Qi++;
            } else if( qs[Qi][0]>A[n-2] ){
                qs[Qi][2] = A[n-2];
                qs[Qi][3] = -1;
                Qi++;
            } else if(qs[Qi][0] == A[Ai]){
                qs[Qi][2] = qs[Qi][3] = qs[Qi][0];
                Qi++;
            } else if(qs[Qi][0] > A[Ai]) {
                
                Ai++;
            } else if (qs[Qi][0]<  A[Ai]) {
                qs[Qi][2] = A[Ai-1];
                qs[Qi][3] = A[Ai];
                Qi++;
            } else {
                Qi++;
                printf("Err handling\n");   
            }
                
            
        }
        
        sort(qs.begin(), qs.end(), [](auto &lhs, auto&rhs){
            return lhs[1] < rhs[1];
        });
        
        for(auto &v: qs) {
            vector<int> a;
            a.push_back(v[2]);
            a.push_back(v[3]);
            ans.push_back(a);
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