class Solution {
    //https://leetcode.com/problems/maximum-strong-pair-xor-i
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size(), ans=0;
        for(int i = 0;i<n;i++) 
            for(int j = i+1;j<n;j++) {
                int &x =nums[i], &y=nums[j];
                if(abs(x-y)<=min(x,y)) ans = max(ans, x^y);
            }
        return ans;
    }
};