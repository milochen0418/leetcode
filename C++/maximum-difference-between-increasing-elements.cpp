class Solution {
    //https://leetcode.com/problems/maximum-difference-between-increasing-elements
public:
    int maximumDifference(vector<int>& nums) {
        int ans = INT_MIN, bottom=INT_MAX;
        for(auto &i:nums) {
            bottom = min(bottom,i);
            ans = max(i-bottom,ans);
        }
        return ans==0?-1:ans;
    }

    int maximumDifference_v01(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n;i++) { 
            for(int j =i+1;j<n;j++) {
                ans = max(ans, nums[j] - nums[i]);
            }
        } 
        return ans==0?-1:ans;
    }

};