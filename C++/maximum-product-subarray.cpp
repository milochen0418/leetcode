class Solution {
    //https://leetcode.com/problems/maximum-product-subarray
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN, max_chasing=1, min_chasing=1;
        for(auto &v: nums) {
            initializer_list<int> list = {v,max_chasing*v,min_chasing*v};
            min_chasing = min(list);
            max_chasing = max(list);
            ans = max(max_chasing,ans);
        }
        return ans;
    }
};