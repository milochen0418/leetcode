class Solution {
    //https://leetcode.com/problems/sort-colors
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int L = 0,R = n-1;
        
        while(L<=R) {
            if(nums[R] == 2) {
                R--;
            } else if(nums[L] == 2) {
                swap(nums[L++], nums[R]);
            } else {
                L++;
            }
        }
        
        L = 0;
        while(L<=R) {
            if(nums[R] == 1) {
                R--;
            } else if(nums[L] == 1) {
                swap(nums[L++], nums[R]);
            } else {
                L++;
            }
        }
    }
};