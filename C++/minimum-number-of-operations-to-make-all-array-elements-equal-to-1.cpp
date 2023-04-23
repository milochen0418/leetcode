class Solution {
    //https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
    //article https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/discuss/3447720/C%2B%2B-O(1)-Brute-Force-or-Explanation
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //Case A. if there is an one in default nums, then return the solution
        for(int i = 0;i<n;i++) {
            if(nums[i]==1) {
                int cntone = 0;
                for(int j=0;j<n;j++) if(nums[j]==1)cntone++;
                return n-cntone;
            }
        }
        //Case B. We should make the first one in nums. minv is minimum steps to make one
        int minv = INT_MAX;
        //We try all possible gcd(nums[i..j]) to find out the minumum range[i..j] that can be 1
        for(int i = 0; i<n;i++) {
            for(int j = i;j<n;j++) {
                int tmp = 0;
                for(int k = i;k<=j;k++) 
                    tmp = gcd(tmp, nums[k]);
                if(tmp == 1) minv=min(minv, j-i);
            }
        }
        return minv==INT_MAX?-1:minv+n-1;
    }    
};