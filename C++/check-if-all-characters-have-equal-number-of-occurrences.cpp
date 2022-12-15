class Solution {
    //https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences
public:
    bool areOccurrencesEqual(string s) {
        vector<int> v=vector<int>(26,0);
        int ref =0 ;
        for(auto &c: s) ref=++v[c-'a'];
        for(auto &i: v) if(i!=0 && i !=ref) return false;
        return true;
    }
};