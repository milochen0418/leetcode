class Solution {
    //https://leetcode.com/problems/longest-alternating-subarray
    //article https://leetcode.com/problems/longest-alternating-subarray/discuss/4144699/C%2B%2B-or-time-O(N)-space-O(1)-two-pass
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(); 
        for(int i = 0;i<n-1;i++) nums[i] = nums[i+1]-nums[i];
        nums.pop_back();
        //The above code is convert [2,3,4, 3,4] into [1,1,-1,1]
        n = nums.size();
        int ans=-1;
        int L=0,R=0;
        while(R<n) {
            int sign = -1*(2*((R-L)%2)-1);
            //printf("L,R,nums[R], Sign = %2d,%2d,%2d, %2d\n", L,R,nums[R],sign);
            if(nums[L]!=1) {
                L=L+1;
                R=L;
            } else if (nums[R]==sign) {
                ans=max(ans,R-L+2);
                R=R+1;
            } else {
                L=R;
                R=R+1;                
            }
        }
        return ans;
    }
};