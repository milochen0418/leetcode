class Solution {
    //https://leetcode.com/problems/maximum-product-subarray
    //article https://leetcode.com/problems/maximum-product-subarray/discuss/2214438/C%2B%2B-or-2-approach-to-make-time-O(n)-space-O(1)-or-Explanation
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int can = 1;
        for(auto &v: nums) {
            if(v!=0) {
                can*=v;
                ans=max(ans,can);
            } else {
                ans=max(ans,0);
                can = 1;
            }
        }
        reverse(nums.begin(), nums.end());
        can = 1;
        for(auto &v: nums) {
            if(v!=0) {
                can*=v;
                ans=max(ans,can);
            } else {
                ans=max(ans,0);
                can = 1;
            }
        }
        return ans;        
    }

    int maxProductByReferSolution(vector<int>& nums) {
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