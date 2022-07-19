class Solution {
    //https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<int> indices;
        for(int i = 0;i<n;i++) { 
            if(s1[i]!=s2[i]) indices.push_back(i);
            if(indices.size()>2) return false;
        }
        if(indices.size()==0) return true;
        if(indices.size()==1) return false;
        return ( s1[indices[0]] == s2[indices[1]] && s1[indices[1]] == s2[indices[0]] );
    }
};