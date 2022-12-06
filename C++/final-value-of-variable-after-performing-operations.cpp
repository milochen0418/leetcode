class Solution {
    //https://leetcode.com/problems/final-value-of-variable-after-performing-operations
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto &s: operations) ans+=((s[1]=='+')*2)-1;
        return ans;
    }
};