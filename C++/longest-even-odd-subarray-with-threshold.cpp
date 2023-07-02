class Solution {
    //https://leetcode.com/problems/longest-even-odd-subarray-with-threshold
    //article https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/discuss/3706846/C%2B%2B-simple-9-lines-O(N)-or-Sliding-Window
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int L=0, R=0, ans=0, n=nums.size();        
        while(L<n && R<n) {
            if(! (nums[L]%2==0 && nums[L]<=threshold)) {
                R=++L;
            } else if(R+1<n && nums[R+1]<=threshold && nums[R]%2!=nums[R+1]%2) {
                R=R+1;
                ans = max(ans, R-L+1);
            } else {
                L=++R;
                ans = max(ans ,1);
            }
        }
        return ans;
    }
};