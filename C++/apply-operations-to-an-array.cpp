class Solution {
    //https://leetcode.com/problems/apply-operations-to-an-array/
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n-1;i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        vector<int> ans = vector<int>(n,0);
        int j = 0; 
        for(int i = 0; i<n;i++) {
            if(nums[i] >0 ) {
                ans[j++] = nums[i];
            }
        }
        return ans;

    }
};