class NumArray {
    //https://leetcode.com/problems/range-sum-query-mutable/
    //article https://leetcode.com/problems/range-sum-query-mutable/discuss/2891915/C%2B%2B-or-Segment-Tree
    //Topic: Segment Tree
public:
    vector<int>* pNums;
    
    
    NumArray(vector<int>& nums) {
        pNums = &nums;
        vector<int>& A = *pNums;
        st_root = ST_build(0, A.size()-1);   
    }
    
    void update(int index, int val) {
        ST_update(index, val);
    }
    
    int sumRange(int left, int right) {
        //vector<int>& A = *pNums;
        //if(right<left) return 0;
        //if(left<0 || index>=A.size()) return;
        return ST_sum(st_root, left, right);
    }
private:    
    struct STNode {
        int L,R,sum;
        STNode*left,*right;
        STNode(int l, int r, int _sum=0, STNode* _left=nullptr, STNode* _right=nullptr) {
            L=l;
            R=r;
            sum = _sum;
            left =_left;
            right=_right;
        }
    };
    
    /*
    struct TestStruct {
        int id;
        TestStruct() : id(42)
        {
        }
    };
    */
    
    STNode *st_root;
    
    void ST_update(int index, int new_val) {
        vector<int>& A = *pNums;
        //if(index<0 || index>=A.size()) return;
        int inc = new_val - A[index];
        A[index] = new_val;
        //printf("inc=%d\n",inc);
        STNode *node = st_root;
        while(node != nullptr) {
            //printf("node->sum+=inc , sum=%d, inc=%d\n",node->sum, inc);
            node->sum+=inc;
            //printf("node->sum= %d after add inc=%d, with(L,R)=(%d,%d)\n",node->sum, inc,node->L, node->R);
            int M = node->L + (node->R-node->L)/2;
            if(index<=M) 
                node=node->left;
            else 
                node=node->right;
        }        
    }
    STNode* ST_build(int L, int R) {
        vector<int>& A = *pNums;
        if(L==R) {
            //printf("ST_build L,R,A[L]=%d,%d,%d\n",L,R,A[L]);
            return new STNode(L,R,A[L],nullptr, nullptr);
            
        }
        STNode* node = new STNode(L,R,0,nullptr,nullptr);
        int M = L + (R-L)/2;
        node->left = ST_build(L, M); 
        node->right = ST_build(M+1, R); 
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    
    int ST_sum(STNode*node, int L, int R) {//get sum value of [L..R]
        if(!node) return 0; 
        vector<int>& A = *pNums;
        if(node->L == L && node->R == R) return node->sum;
        //for(int i = 0; i<A.size();i++) printf("%d, ", A[i]);
        //printf("\n");
        int M = node->L + (node->R-node->L) /2;
        if(R<=M) {
            return ST_sum(node->left, L, R);
        } 
        else if(L>=M+1) {
            return ST_sum(node->right, L, R);
        } 
        else {
            return ST_sum(node->left, L,M) + ST_sum(node->right, M+1,R);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */