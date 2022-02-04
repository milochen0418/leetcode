class Solution {
    //https://leetcode.com/problems/contiguous-array
/* test-case
[0,1]
[0,1,0]
[0,1,1,0,1,1,1,0]


*/

public:
    int findMaxLength(vector<int>& nums) {
        int total_1 = accumulate(nums.begin(), nums.end(), 0);
        int total_0 = nums.size() - total_1;
        return min(total_1, total_0)*2;
    }
};