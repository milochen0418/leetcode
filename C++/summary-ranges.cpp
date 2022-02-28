class Solution {
    //https://leetcode.com/problems/summary-ranges
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        nums.push_back(nums.size()==0?0:nums.back());
        int begin=nums[0],end=nums[0];        
        for(int i=1;i<nums.size();i++) {
            if((long)nums[i]==(long)nums[i-1]+1) {
                end = nums[i];
            } else {
                v.push_back(begin!=end?to_string(begin)+"->"+to_string(end) : to_string(begin));
                begin = end = nums[i];
            }
        }
        return v;
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