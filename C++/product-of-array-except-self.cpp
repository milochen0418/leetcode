class Solution {
    //https://leetcode.com/problems/product-of-array-except-self
/* testcase 
[1,2,3,4]
[-1,1,0,-3,3]

*/    
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long product = 1;
        for(auto num: nums) {
            product *= (long)num;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = (product/nums[i]);
        }
        return ans;
    }
};