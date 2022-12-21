class Solution {
    //https://leetcode.com/problems/build-array-from-permutation/
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> A = vector<int> (nums.size(),0);
        for(int i = 0; i <nums.size();i++) {
            A[i] = nums[nums[i]];
        }
        return A;
    }
};