class NumArray {
    //https://leetcode.com/problems/range-sum-query-immutable/
public:
    vector<int>* pNums;
    NumArray(vector<int>& nums) {
        pNums=&nums;
        vector<int>& A = *pNums;
        for(int i = 1;i<A.size();i++) A[i]=A[i] + A[i-1];
    }
    
    int sumRange(int left, int right) {
        vector<int>& A = *pNums;
        int A_left_1 = left-1<0?0:A[left-1];
        return A[right] - A_left_1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */