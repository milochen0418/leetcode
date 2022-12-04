class Solution {
    //https://leetcode.com/problems/minimum-average-difference
    //article: https://leetcode.com/problems/minimum-average-difference/discuss/2874762/C%2B%2B-or-prefix-sum
public:
    typedef unsigned long long ull;
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        //[0,1,2,3,4,5], n = 6
        //average difference of 2 is absolute difference between the average of i+1 3  and n-(i+1) 6-3 
        //so it is average is care about [0,1,2] and [3,4,5]
        //For more consideration, we need to take care large integer.  
        int ans = -1;//find out the index with the minimum average difference
        ull min_val = (ull)INT_MAX;
        vector<ull> psum = vector<ull>(n,0);
        for(int i = 0;i<n;i++) psum[i] = (ull)nums[i];
        for(int i = 1;i<n;i++) psum[i] = psum[i-1] + psum[i];
        for(int i = 0; i<n;i++) {
            ull L = (psum[i])/((ull)i+1);
            ull R = i==n-1?0:(psum[n-1]-psum[i])/((ull)n-((ull)i+1));
            ull avg_diff = R>L?R-L:L-R;
            if (avg_diff < min_val) {
                ans = i;
                min_val = avg_diff;
            }
        }
        return ans;
    }
};