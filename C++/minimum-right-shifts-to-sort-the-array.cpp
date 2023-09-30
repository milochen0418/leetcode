class Solution {
    //https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array
public:
    int minimumRightShifts(vector<int>& nums) {
        if(nums.size()==1) return 0;
        nums.push_back(nums[0]);
        int n = nums.size(), cnt = 0, ans=0 ;
        for(int i = 1; i<n; i++) {
            if(nums[i-1]>nums[i]) {
                ans = n-i-1;
                if(++cnt>=2)break;
            }
        }
        if(cnt==1) return ans;
        else return -1;
        
    }
};