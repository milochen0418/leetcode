class Solution {
    //https://leetcode.com/problems/merge-strings-alternately
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.length()<=word2.length()) {
            string& s1=word1, &s2=word2;
            string ans="";
            int m = s1.length(), n=s2.length();
            for(int i = 0;i<n;i++) {
                if(i<m)ans.push_back(s1[i]);
                ans.push_back(s2[i]);
            }
            return ans;
        } else {
            string& s1=word2, &s2=word1;
            string ans="";
            int m = s1.length(), n=s2.length();
            for(int i = 0;i<n;i++) {
                ans.push_back(s2[i]);
                if(i<m)ans.push_back(s1[i]);
            }
            return ans;
            
        }
    }
};