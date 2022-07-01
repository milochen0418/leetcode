class Solution {
    //https://leetcode.com/problems/isomorphic-strings/
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        vector<int> vs;
        vector<int> vt;
        int cnts=1;
        int cntt=1;
        
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(mps.find(s[i]) == mps.end()) mps[s[i]] = cnts++;
            if(mpt.find(t[i]) == mpt.end()) mpt[t[i]] = cntt++;
            vs.push_back(mps[s[i]]);
            vt.push_back(mpt[t[i]]);
        }
        return vs==vt;
    }
};