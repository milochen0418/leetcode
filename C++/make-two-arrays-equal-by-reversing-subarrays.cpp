class Solution {
    //https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays
    //article https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/discuss/3019270/C%2B%2B-or-counting-approach
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> mpt=vector<int>(1001,0),mpa = mpt;
        for(auto &i:target) mpt[i]++;
        for(auto &i:arr) mpa[i]++;
        return mpt==mpa;
    }
};