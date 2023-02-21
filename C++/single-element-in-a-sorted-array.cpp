class Solution {
    //https://leetcode.com/problems/single-element-in-a-sorted-array/
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n<2 || nums[n-2]!=nums[n-1]) return nums[n-1];
        int m = n;
        n=(n+1)/2;
        int L = 0, R=n-1;
        while(L<=R) {
            int Mp = (L+(R-L)/2);    
            int M = Mp*2;
            //printf("([L,R],M) = ([%d,%d],%d)\n",L*2,R*2,M);
            if(   (M-1<0  || nums[M-1] < nums[M])
               && (nums[M] < nums[M+1])
            ) return nums[M];
            if(nums[M] < nums[M+1]) {
                R=Mp-1;
            } else {
                L=Mp+1;
            }
        }
        return -1;
    }

    int singleNonDuplicate_v01(vector<int>& nums) {
        //[0,0,1,1,4,4,5,7, 7,8, 8,9, 9]
        // 0   2   4   8   10   12   14
        int n = nums.size();
        if(n<2) return nums[0];
        for(int i = 0; i<n; i+=2) {
            if(nums[i+1]!=nums[i]) return nums[i];
        }
        return -1;
    }
};