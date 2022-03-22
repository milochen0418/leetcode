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
    void answer2(vector<int>& nums) {
        int i=0,cnt=0, n = nums.size();
        while(nums[i] != 0) if(++i>=n) break;//no moving before zero
        for(; i<n; i++ ) {
            if(nums[i] == 0) {
                ++cnt;
            } else {
                //swap(nums[i-cnt], nums[i]) but nums[i-cnt] always zero
                //optimize here
                nums[i-cnt] = nums[i];
                nums[i] = 0;
            }
        }
    }
    void answer3(vector<int>& nums) {
        int i=0,cnt=0, n = nums.size();
        while(nums[i] != 0) if(++i>=n) break;//no moving before zero
        for(; i<n; i++ ) {
            if(nums[i] == 0) {
                ++cnt;
            } else {
                nums[i-cnt] = nums[i];
            }
        }
        i=n-cnt;
        while(i<n)nums[i++]=0;      
    }

};
