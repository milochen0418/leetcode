class Solution {
    //https://leetcode.com/problems/valid-anagram
    //article https://leetcode.com/problems/valid-anagram/discuss/2309667/C%2B%2B-or-Time-O(N)-Space-O(1)-by-vector
public:
    bool isAnagram(string s, string t) {
        vector<int>mps = vector<int>(256,0);
        vector<int>mpt = vector<int> (256,0);
        for(auto&c:s)mps[c]++;
        for(auto&c:t)mpt[c]++;
        return mps==mpt;
    }
};