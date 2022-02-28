class Solution {
    //https://leetcode.com/problems/summary-ranges
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5112424425446674
    //article https://leetcode.com/problems/summary-ranges/discuss/1806223/C%2B%2B-or-12-lines-or-put-dummy
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        nums.push_back(nums.size()==0?0:nums.back());
        int begin=nums[0],end=nums[0];        
        for(int i=1;i<nums.size();i++) {
            //if((long)nums[i]==(long)nums[i-1]+1) {
            if(nums[i]-1==nums[i-1]){                
                end = nums[i];
            } else {
                ans.push_back(begin!=end?to_string(begin)+"->"+to_string(end) : to_string(begin));
                begin = end = nums[i];
            }
        }
        return ans;
    }
};

/* testcase 
[3,5,8,10,11]
[0,2,3,4,6,8,9]
[]
[3]
[0]
[3,5,8,10,11]
[0,2,3,4,6,8,9]
[]
[3]
[0]
[-2147483648,-2147483647,2147483647]
*/