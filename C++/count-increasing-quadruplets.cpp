class Solution {
    //https://leetcode.com/problems/count-increasing-quadruplets/
public:
    typedef long long ll;
    long long countQuadruplets(vector<int>& nums) {
        /*
        Observation. 
        
        0<= h<i<j<k <n
        nums[h]<nums[j]<nums[i]<nums[k]
        
        That's we can find all pair i<j (i,j) s.t. nums[i]>nums[j] by O(N^2) first 
        by the 2-level loop. 
        
        After we find out nums[i]>nums[j]...
        We need find the elements e_h in nums[0 .. i-1] s.t. e_h < nums[j]
        We need find the elements e_k in nums[j+1..n-1] s.t. e_k > nums[i]

        This observation is contributed by ZZZ, 哎呀呀 in LeetCode Contest After Party
        */
        return 0;
    }

};