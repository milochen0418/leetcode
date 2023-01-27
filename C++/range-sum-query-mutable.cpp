
class NumArray {
    //https://leetcode.com/problems/range-sum-query-mutable/
public:
    vector<int>* pNums;
    NumArray(vector<int>& nums) {
        pNums = &nums;
        root = ST_build(0, nums.size()-1);
    }
    void update(int index, int val) {
        ST_update(index, val);
    }
    int sumRange(int left, int right) {    
        return ST_sum(root, left, right);
    }
	
private:    
    
    struct STNode {
        int L;
        int R;
        int sum;
        STNode* left;
        STNode* right;
        STNode(int _L, int _R, int _sum, STNode* _left, STNode* _right) {
            L=_L,R=_R, sum=_sum;
            left=_left, right=_right;
        }
    };
    STNode* root; 
    
    STNode* ST_build(int L , int R) { 
        if(L==R) return new STNode(L,R,(*pNums)[L],nullptr,nullptr);
        int M = L+(R-L)/2;
        STNode* node_l = ST_build(L,M);
        STNode* node_r = ST_build(M+1,R);
        STNode* node = new STNode(L,R,node_l->sum + node_r->sum, node_l, node_r);
        return node;
    }
    
    void ST_update(int index, int val) { 
        int inc = val - (*pNums)[index];
        (*pNums)[index] = val;
        STNode *node = root;
        while(node) { 
            node->sum+=inc;
            int M = node->L + (node->R-node->L)/2;
            if(index<=M) {
                node=node->left;
            } else {
                node=node->right;
            }
        }
    }
    
    int ST_sum(STNode* node, int L, int R) {
        if(L==R) return (*pNums)[L];
        if(L==node->L && R==node->R) return node->sum;
        int M = node->L + (node->R-node->L)/2;
        if(R<=M) {
            return ST_sum(node->left, L, R);
        } else if (M+1<=L) {
            return ST_sum(node->right, L, R);
        } else {
            return ST_sum(node->left, L,M) + ST_sum(node->right, M+1,R);
        }
    }
    
};
