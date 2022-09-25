class Solution {
    //https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and
    //add article https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/discuss/2621192/C%2B%2B-or-array-approach
public:
    int longestSubarray(vector<int>& nums) {
        //what is maximum possible bitwise AND?
        int k = INT_MIN;
        for(auto &i: nums) {
            k = max(k,i);
        }
        int ans = 0;
        int v = 0;
        for(int i = 0; i < nums.size();i++) {
            if(nums[i]==k) {
                v++;
            } else {
                v = 0;
            }
            ans = max(v,ans);
        }           
        return ans;
    }
};