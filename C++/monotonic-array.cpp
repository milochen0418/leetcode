class Solution {
    //https://leetcode.com/problems/monotonic-array
    //article https://leetcode.com/problems/monotonic-array/discuss/3057767/C%2B%2B-differential-array-O(N)-9-lines
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n-1;i++) nums[i] = nums[i+1]-nums[i];
        int poscnt=0, negcnt=0;
        for(int i = 0;i<n-1;i++) {
            poscnt+=nums[i]>0;
            negcnt+=nums[i]<0;
            if(poscnt>0 && negcnt>0) return false;
        }
        return true;
    }
};