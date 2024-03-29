class Solution {
    //https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
    //article https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/discuss/3023639/C%2B%2B-one-pass-10-lines
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), prev_i=-1*(1e5+1);
        for(int i=0;i<n;i++) {        
            if(nums[i]==1) {
                int len = i-prev_i-1;
                if(len<k) return false;                    
                prev_i=i;
            }
        }
        return true;
    }

    bool kLengthApart_v02(vector<int>& nums, int k) {
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