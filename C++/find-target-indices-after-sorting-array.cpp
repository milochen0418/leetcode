class Solution {
    //https://leetcode.com/problems/find-target-indices-after-sorting-array
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size();i++) {
            if(nums[i]>target) {
                break;
            } else if(nums[i]==target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};