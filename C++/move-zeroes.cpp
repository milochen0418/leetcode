class Solution {
    //https://leetcode.com/problems/move-zeroes/
    //article https://leetcode.com/problems/move-zeroes/discuss/1873790/C%2B%2B-or-counter-approach-or-space-O(1)-time-O(n)-and-optimal
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5173709149318201/
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0, n = nums.size();
        for(int i = 0; i<n; i++ ) 
            if(nums[i] == 0) 
                ++cnt;
            else 
                swap(nums[i], nums[i-cnt]);
    }
};
