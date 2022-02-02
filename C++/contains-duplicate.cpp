class Solution {
    //https://leetcode.com/problems/contains-duplicate/
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num:nums) {
            if(s.find(num) != s.end()) {
                return true;
            } else {
                s.insert(num);
            }
        }
        return false;
    }
};