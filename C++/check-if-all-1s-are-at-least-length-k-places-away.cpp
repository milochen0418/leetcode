class Solution {
    //https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), i=0;
        int prev_i=-1;
        for(i=prev_i+1;i<n;i++) {        
            if(nums[i]==1) {
                if(prev_i!=-1) {
                    int len = i-prev_i-1;
                    if(len<k) return false;                    
                }
                prev_i=i;
            }
        }
        return true;
    }

    bool kLengthApart_v01(vector<int>& nums, int k) {
        int n = nums.size(), i=0;
        while(i<n && nums[i]!=1)i++;
        int prev_i = i;
        for(i=prev_i+1;i<n;i++) {
            if(nums[i]==1) {                
                int len = i-prev_i-1;
                if(len<k) return false;                    
                prev_i=i;
            }
        }
        return true;
    }

};