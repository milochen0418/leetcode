class Solution {
    //https://leetcode.com/problems/binary-search
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int H = nums.size()-1;
        while(L<=H) {
            int M = (H+L)/2;
            if(target < nums[M]) {
                H = M-1;
            }else if(target > nums[M]) {
                L = M+1; 
            } else {
                return M;
            }
        }
        return -1;
    }
};