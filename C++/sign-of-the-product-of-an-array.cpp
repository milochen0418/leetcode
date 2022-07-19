class Solution {
    //https://leetcode.com/problems/sign-of-the-product-of-an-array
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto&i:nums) {
            if(i==0) return 0;
            if(i<0)ans*=-1;
        }
        return ans;
    }
};