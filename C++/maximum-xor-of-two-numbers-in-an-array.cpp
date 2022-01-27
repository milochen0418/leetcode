class Solution {
    //https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
public:
    int findMaximumXOR(vector<int>& nums) {
        int mymax = INT_MIN;
        int n = nums.size();
        if(n==1) return 0;
        for(int i=0;i<n-1;i++) {
            for(int j = i+1; j<n; j++) {
                mymax = max(mymax, nums[i]^nums[j]);
            }
        }
        return mymax;
    }
};