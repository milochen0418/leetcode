class Solution {
    //https://leetcode.com/problems/semi-ordered-permutation/
public:
    // [...1...  n...]  => (n-1-R) + (L)
    //     L     R        
    // [...n ... 1...]   => (n-1-R) + (L) -1
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int L=0, R=0;
        for(int i = 0; i<nums.size(); i++) 
            if(nums[i] == 1) 
                L = i;
        for(int i = 0; i<nums.size(); i++) 
            if(nums[i] == n) 
                R = i;
        if(R<L) ans=ans-1; 

        ans = ans + (n-1-R) + (L);
        return ans; 
    }
};