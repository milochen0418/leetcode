class NumArray {
    //https://leetcode.com/frontendx/problems/range-sum-query-immutable
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        a = vector<int>(n+1, 0);
        for(int i = 1; i < n+1; i++) {
            a[i] = a[i-1] + nums[i-1];
        }
        //               L, R 
        //nums =    [03,04,09,06]
        //   a = [00,03,07,16,32]
        //          L-1     R      
        //sumrange[L..R] = a[R+1] - a[L+1-1]
        
    }
    
    int sumRange(int left, int right) {
        return a[right+1] - a[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */