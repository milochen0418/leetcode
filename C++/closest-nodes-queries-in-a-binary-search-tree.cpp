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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> A;
        A.push_back(INT_MIN);
        inorder(root,A);
        A.push_back(INT_MAX);
        printf("\nA = ");
        for(auto &i:A) printf("%d, ", i);
        printf("\n M seq = ");
        int n = A.size();
        for(auto q:queries) {
            vector<int> a;
            int L = 0, R = n-1;
            int min_i = -1;
            int max_i = -1;
            int M = L + (R-L)/2;
            while(L<R) {
                //M = L/2 + R/2 = L + (R/2-L/2) = L + (R-L)/2
                M = L + (R-L)/2;
                printf("(%d,%d)-> M=%d, \n", min_i,max_i, M);
                if(M==0 || M == n-1) break;
                if(A[M] == q) {
                    min_i = q;
                    max_i = q;
                    break;
                }
                //We want to find the M satisfy that A[M-1] <= q <= A[M+1]
                if(q < A[M]) { 
                    min_i = A[M-1];
                    max_i = A[M];
                    R = M-1;
                } else {//case A[M] < q
                    min_i = A[M];
                    max_i = A[M+1];
                    L = M+1;
                } 
            }
            printf("\n", M);
            if(min_i == INT_MIN) min_i = -1;
            if(max_i == INT_MAX) max_i = -1;
            
            a.push_back(min_i);
            a.push_back(max_i);
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


    vector<vector<int>> closestNodes_Ver01(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        for(auto &q: queries) {
            ans.push_back(sol(root, q));
        }
        return ans;
    }
    vector<int> sol(TreeNode* root, int q) {
        vector<int> ret;
        ret.push_back(find_min(root, q));
        ret.push_back(find_max(root, q));
        return ret;
    }
    
    // find the min which is the largest value smaller or equal than q 
    int find_min(TreeNode* root, int q) { 
        int c = -1; // candidate
        while(root != nullptr) {
            int v = root->val;
            if(v == q) {
                return q;
            } else if(v < q) {
                c = v;
                root = root->right;
            } else { //if(v > q)
                root = root->left;
            }
        }
        return c;
    }
    // find the max which is the smallest value larger or equal than q 
    int find_max(TreeNode* root, int q) {
        int c = -1; // candidate
        while(root != nullptr) {
            int v = root->val;
            if(v == q) {
                return q;
            } else if(v > q) {
                c = v;
                root = root->left;
            } else { //if(v > q)
                root = root->right;
            }
        }
        return c;

    }
    
};