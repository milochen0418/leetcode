class Solution {
    //https://leetcode.com/problems/remove-element/submissions/
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = nums.size();
        while (i < k) {
            if(nums[i] == val) {
                nums[i] = nums[k-1];
                k--;
            } else {
                i++;
            }
        }
        return k;
    }
};