class Solution {
    //https://leetcode.com/problems/find-peak-element/
public:
    int findPeakElement(vector<int>& nums) {
        int state = 0;
        for(int i = 0; i <= nums.size(); i++) {
            long long nums_i = i<nums.size() ? nums[i]: LONG_MIN;
            long long nums_i_1 = i-1>=0 ? nums[i-1]:LONG_MIN;
            if(state == 0) {
                //if(nums[i] > nums[i-1]) state = 1;    
                if(nums_i > nums_i_1) state = 1;    
            } else if(state == 1) {
                //if(nums[i] < nums[i-1]) state = 2;
                if(nums_i < nums_i_1) state = 2;
            } 
            if(state == 2) return i-1;
        }
        return -1;
    }
};