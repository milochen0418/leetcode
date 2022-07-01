class Solution {
    //https://leetcode.com/problems/isomorphic-strings/
public:
    bool isIsomorphic(string s, string t) {
        vector<int> as(256,0);
        vector<int> at(256,0);
        int cnts=1, cntt=1;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(as[s[i]]==0) as[s[i]] = cnts++;
            if(at[t[i]]==0) at[t[i]] = cntt++;
            if(as[s[i]] != at[t[i]]) return false;
        }
        return true;
    }

    bool isIsomorphicAnswerVer02(string s, string t) {
        unordered_map<char,int> mps, mpt;
        int cnts=1, cntt=1;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(mps.find(s[i]) == mps.end()) mps[s[i]] = cnts++;
            if(mpt.find(t[i]) == mpt.end()) mpt[t[i]] = cntt++;
            if(mps[s[i]] != mpt[t[i]]) return false;
        }
        return true;
    }

    bool isIsomorphicAnswerVer01(string s, string t) {
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