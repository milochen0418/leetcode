class Solution {
    //https://leetcode.com/problems/find-subarrays-with-equal-sum
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size(), j=0;
        unordered_set<int> s;
        for(int i=n-1;i>=1;i--,j++) {
            nums[i] = nums[i] + nums[i-1];
            s.insert(nums[i]);
            if(s.size() != j+1) return true;
        }
        //all kind of sum of subarray with length 2 is from nums[1..n-1]
        return false;
    }
};