class Solution {
    //https://leetcode.com/problems/move-zeroes/
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0, n = nums.size();
        for(int i = 0; i<n; i++ ) 
            if(nums[i] == 0) 
                ++cnt;
            else 
                swap(nums[i], nums[i-cnt]);
    }
};