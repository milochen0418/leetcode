class Solution {
    //https://leetcode.com/problems/permutation-in-string/
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()>s1.length()) false;
        vector<int> s1v(26);
        for(auto &c:s1) s1v[c-'a']+=1;
        for(int i = 0; i<s2.length()-s1.length(); i++) { 
            string s2sub = s2.substr(i,s1.length());
            vector<int> s2v(26);
            for(auto &c:s2sub) {
                s2v[c-'a']+=1;
            }
            if(s1v == s2v) return true;
        }
        return false;

            
    }
};

/* testcase 
"ab"
"eidbaooo"
"ab"
"eidboaoo"
"adc"
"dcda"
*/