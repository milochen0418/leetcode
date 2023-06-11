class Solution {
    //https://leetcode.com/problems/neither-minimum-nor-maximum/
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2) return -1;
        int minv = INT_MAX, maxv= INT_MIN;
    
        for(auto &i: nums) {
            minv = min(minv, i);
            maxv = max(maxv, i);
        }
        
        for(auto &i:nums) {
            if(i!=minv && i!=maxv) return i;
        }
        return -1;
    }
};