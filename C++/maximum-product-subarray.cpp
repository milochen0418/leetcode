class Solution {
    //https://leetcode.com/problems/maximum-product-subarray
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN, max_chasing=1, min_chasing=1;
        for(auto &v: nums) {
            int maxv = max_chasing*v;
            int minv = min_chasing*v;
            min_chasing = min(v,min(maxv,minv));
            max_chasing = max(v,max(maxv,minv));
            ans = max(max_chasing,ans);
        }
        return ans;
    }
};