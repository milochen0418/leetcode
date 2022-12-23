class Solution {
    //https://leetcode.com/problems/check-if-array-is-sorted-and-rotated
    //article https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/discuss/2942632/C%2B%2B-or-3-Pass-time-O(N)-space-O(1)
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), cnt=0;
        for(int i = 0;i<n;i++)             
            if(nums[i%n] > nums[(i+1)%n] && ++cnt>1)  
                return false;
        return true;
    }

    bool check_3pass(vector<int>& nums) {
        //case no repeat value in nums 
        //We only need to find the minimum element, then start to circle travel
        //But repeat case like 
        //[6,10,6]
        //[7,9,1,1,1,3]
        //We should process these cases when minimum value is not unique.
        
        int begin=0, minv = INT_MAX, n = nums.size();
        for(int i = 0; i < n;i++) {
            if(nums[i]<minv) {
                begin = i;
                minv = nums[i];
            }
        }
        //special processing edge case like [6,10,6]
        if(nums[n-1]==minv) {
            int j = n-1;
            while(j>=0 && nums[j]==minv)j--;
            begin = j+1;
        }
        
        int prev_v=minv;
        for(int i = 1;i<n;i++) {
            if(nums[(begin+i)%n] < prev_v) return false;
            prev_v = nums[(begin+i)%n];
        }
        return true;
    }
};