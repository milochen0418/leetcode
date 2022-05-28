class Solution {
    //https://leetcode.com/problems/missing-number/
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<=nums.size();i++) ans= ans^i;
        for(auto& i:nums) ans = ans^i;
        return ans;
    }
    int missingNumberXOR(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<=nums.size();i++) ans= ans^i;
        for(auto& i:nums) ans = ans^i;
        return ans;        
    }
    int missingNumberSort(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(ans = 0; ans<nums.size();ans++) if(ans!=nums[ans]) break;
        return ans;
    }

};