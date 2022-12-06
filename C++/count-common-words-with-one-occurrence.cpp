class Solution {
    //https://leetcode.com/problems/count-common-words-with-one-occurrence
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1,mp2;
        unordered_set<string> sc;
        for(auto &w:words1) mp1[w]++;
        for(auto &w:words2) mp2[w]++;
        for(auto &[w,t]:mp1) if(t==1) if(mp2[w] == 1) sc.insert(w);
        for(auto &[w,t]:mp2) if(t==1) if(mp1[w] == 1) sc.insert(w);
        return sc.size();
    }
};