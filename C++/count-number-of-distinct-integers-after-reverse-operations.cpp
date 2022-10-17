class Solution {
    //https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> ss;
        for(auto &i: nums) {
            ss.insert(i);
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int reverse = atoi(s.c_str());
            ss.insert(reverse);
        }      
        return ss.size();
    }
};