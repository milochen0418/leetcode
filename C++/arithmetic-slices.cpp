class Solution {
    //https://leetcode.com/problems/arithmetic-slices/
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //Observation
        //[1]                 (begin=0,end=0, diff=0)
        //[1,2]               (begin=0,end=1, diff=1)
        //[1,2] + [3] + 1     (end-begin-1 = 2-0-1)
        //[1,2,3] + [4] + 2   (end-begin-1 = 3-0-1)
        //[1,2,3,4] + [5] + 3 (end-begin-1 = 4-0-1, diff=1)  
        //[1,2,3,4,5] + [7]   (begin=4, end=5, diff=2) //when diff change , then reset here
        //[1,2,3,4,5] + [7] + [9]  + 1  (begin=4, end=6,  end-begin-1=1)
        //[1,2,3,4,5] + [7] + [9] + [11] + 2  (begin=4, end=7,  end-begin-1=2)
        
        int n = nums.size();
        if(n<3) return 0;
        int begin = 0;
        int end = 1;
        int diff = nums[end] - nums[begin];
        int cnt = 0;
        ++end;
        while(end<n) {
            int podiff = nums[end]-nums[end-1];
            if(podiff != diff) {
                begin = end-1;
                diff = podiff;
            } else {
                cnt += (end -begin-1);
            }
            ++end;
        }
        return cnt;
    }
};