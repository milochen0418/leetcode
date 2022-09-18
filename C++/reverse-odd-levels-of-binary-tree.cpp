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
    //https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
    //add article https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/discuss/2592136/C%2B%2B-or-array-approach 
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> v= vector<TreeNode*>(100000, 0);
        int n = 0;
        queue<TreeNode*> Q;        
        Q.push(root);
        v[n++] = root;
        while(!Q.empty()) {
            TreeNode* e = Q.front();
            Q.pop();
            if(e->left != nullptr) {
                Q.push(e->left);
                v[n++]=e->left;
            }
            if(e->right !=nullptr) {
                Q.push(e->right);
                v[n++]=e->right;
            }
        }
        
        /*
        printf("Tree = ");
        for(int i = 0;i<n-1;i++) {
            printf("%d, ", v[i]->val);
        }
        printf("\n");
        */
        
        /*
        1 
        2 <-- idx = [1, 2] , level =1    
        4  
        8 <-- idx = [7, 14], level =3    
        16
        32 <-- idx = [31, 62], level =5
        */
        int level = 1;
        while( (1<<level)-1 < n ) {
            int begin = (1<<level)-1;
            int end = (1<<(level+1))-2;
            //printf("(level, begin,end) = (%d, %d,%d)\n", level, begin, end);
            int L = begin, R=end;
            while(L<R) {
                swap(v[L]->val, v[R]->val);
                L++;
                R--;
            }
            level = level + 2;
        }
        return root;
    }
};