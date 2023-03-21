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
    //https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
    //article https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/discuss/2256920/C%2B%2B-or-Space-O(1)-Time-O(N)-or-some-new-idea-or-explanation
public:
    typedef long long ll;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while( (ll)(root->val-p->val) * (ll)(root->val-q->val)>0 ) 
            root = (p->val<root->val)?root->left:root->right;
        return root;
    }
    
    TreeNode* lowestCommonAncestor_v03(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while( 
            !(
                (ans->val > p->val && ans->val < q->val) ||
                (ans->val < p->val && ans->val > q->val) ||
                (ans->val == p->val && ans->val < q->val) ||
                (ans->val == p->val && ans->val > q->val) ||
                (ans->val < p->val && ans->val == q->val) ||
                (ans->val > p->val && ans->val == q->val) 
            )
        ) {
            if(p->val<ans->val || q->val<ans->val) {
                ans = ans->left;
            } else {
                ans = ans->right;
            }
        }
        return ans;        
    }
    TreeNode* lowestCommonAncestor_v02(TreeNode* root, TreeNode* p, TreeNode* q) {
        //p=2:2,6
        //q=8,8,6
        
        //p=2:  2,6  <= pA
        //q=4:4,2,6  <= qA
        
        vector<TreeNode*> pA;
        vector<TreeNode*> qA;
        
        TreeNode* node = root;
        while(node->val != p->val) {
            pA.push_back(node);
            if(p->val < node->val) 
                node = node->left;
            else //node->val > p->val
                node = node->right;
        } 
        pA.push_back(node);
        
        node = root;
        while(node->val != q->val) {
            qA.push_back(node);
            if(q->val < node->val) 
                node = node->left;
            else //node->val > q->val
                node = node->right;
        } 
        qA.push_back(node);

        /*
        printf("pA = ");
        for(auto &v: pA) printf("%d, ", v->val);
        printf("\n");
        printf("qA = ");
        for(auto &v: qA) printf("%d, ", v->val);
        printf("\n");
        */
        TreeNode* ans;
        int n = min((int)pA.size(), (int)qA.size());
        for(int i = 0; i<n;i++) {
            if(pA[i]->val == qA[i]->val) {
                ans = pA[i];
            }
        }
        return ans;
        
    }

    TreeNode* smallNode = nullptr;
    TreeNode* largeNode = nullptr;
    TreeNode* lowestCommonAncestor_v01(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Case 1: one is the ancestor to another.
        TreeNode* node;
        int pval = p->val;
        int qval = q->val;
		//Case 1.1: If q is ancestor of p, then in the traveeling of finding p-> val, you can meet q  earilier. 
        node = root;
        while(node->val != pval) {
            if(node == q) return q;
            if(pval < node->val)
                node=node->left;
            else 
                node=node->right;
        }
		//Case 1.2: If p is ancestor of q, then in the travelling of finding q->val, you can meet p earilier. 
        node = root;
        while(node->val != qval) {
            if(node == p) return p;
            if(qval<node->val)
                node=node->left;
            else
                node=node->right;
        }
        
        //Case 2: no one is the ancestor to another.
        if(p->val == q->val) return p;  
        if(p->val<q->val) {
            smallNode = p;
            largeNode = q;
        } else {
            smallNode = q;
            largeNode = p;
        }
        while(smallNode->right!=nullptr) {
            smallNode = smallNode->right;
        }
        while(largeNode->left!= nullptr) {
            largeNode = largeNode->left;
        }
        //Start to find value int the bound (begin,end)  in BST
        int begin = smallNode->val;
        int end = largeNode->val;
        while(!(begin<root->val && root->val<end)) {
            if(root->val > end) 
                root=root->left;
            else 
                root=root->right;
        }
        return root;
    }
};