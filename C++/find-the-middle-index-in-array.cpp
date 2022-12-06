class Solution {
    //https://leetcode.com/problems/find-the-middle-index-in-array
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        //make prefix sum for nums
        vector<int> psum = nums;
        for(int i = 1; i<n;i++) psum[i] = psum[i-1]+psum[i];
        for(int i = 0; i<n;i++) {
            int Lsum = i==0?0:(psum[i]-nums[i]);
            int Rsum = i==n-1?0:(psum[n-1]-psum[i]);
            if(Lsum==Rsum) return i;
        }
        return -1;
    }
};