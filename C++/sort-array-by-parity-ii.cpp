class Solution {
    //https://leetcode.com/problems/sort-array-by-parity-ii
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odds;
        vector<int> evens;
        for(auto &i:nums) (i%2==0?evens:odds).push_back(i);
        vector<int> ans;
        for(int i = 0;i<odds.size();i++) {
            ans.push_back(evens[i]);
            ans.push_back(odds[i]);
        }
        return ans;
    }
};