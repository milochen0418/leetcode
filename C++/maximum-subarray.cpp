class Solution {
    //https://leetcode.com/problems/maximum-subarray
public:

    //greedy algorithm
    int maxSubArray(vector<int>& nums) {
        /*
        [-2,1,-3,4,-1,2,1,-5,4]
        case [L,R]=[0,0]
        [-2] -> -2
        case [L,R]=[1,1]
        [1] -> 1
        case [L,R]=[1,2]
        [1,-3] -> -2
        case [L,R]=[3,3]
        [4] -> 4
        case [L,R]=[3,4]
        [4,-1] -> 3
        case [L,R]=[3,5]
        [4,-1,2] -> 5
        case [L,R]=[3,6]
        [4,-1,2,1] -> 6   <---- max
        case [L,R]=[3,7]
        [4,-1,2,1,-5] -> 1
        case [L,R]=[3,8]
        [4,-1,2,1,-5,4] -> 5
        */ 
        int ans = INT_MIN, val = 0, n = nums.size();
        int L=0, R=0;
        while(L<n && R<n) {
            val += nums[R];
            ans = max(ans, val);
            if(val<0) {
                val = 0;
                L=R+1;
                R=R+1;
            } else {
                R=R+1;
            }
        }
        return ans;
    }
        
    //Kadane's algorithm
    int maxSubArrayByKadane(vector<int>& nums) {
        int val = 0, max_val = INT_MIN;
        for(auto &i:nums) {
            val+=i;
            max_val = max(val,max_val);
            if(val<0) val = 0;
        }
        return max_val;
    }


};