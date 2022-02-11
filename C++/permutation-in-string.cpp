class Solution {
    //https://leetcode.com/problems/permutation-in-string/
public:
    bool checkInclusion(string s1, string s2) {
        
        int s1_len = s1.length();
        int s2_len = s2.length();
        if(s1_len > s2_len) return false;
        vector<int> s1v(26,0);
        vector<int> s2v(26,0);
        for(int i=0;i<s1_len;i++) {
            s1v[s1[i]-'a']+=1;
            s2v[s2[i]-'a']+=1;
        }
        if(s1v == s2v) return true;
        for(int i = 1; i<= s2_len - s1_len ; i++) { 
            s2v[s2[i-1]-'a']-=1;
            s2v[s2[i+s1_len-1]-'a']+=1;
            if(s1v == s2v) return true;
        }
        return false;
    }
    
    bool answer1(string s1, string s2) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        if(s1_len > s2_len) false;
        
        vector<int> s1v(26,0);
        for(auto &c:s1) s1v[c-'a']+=1;

        for(int i = 0; i<= s2_len - s1_len ; i++) { 
            string s2sub = s2.substr(i,s1_len);
            vector<int> s2v(26,0);
            for(auto &c:s2sub) s2v[c-'a']+=1; 
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
"ros"
"horse"
*/