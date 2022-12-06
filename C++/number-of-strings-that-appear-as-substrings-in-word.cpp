class Solution {
    //https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans =0;
        for(auto &s:patterns) ans+= is_substring(s,word);
        return ans;
    }
    
    // Refer https://www.geeksforgeeks.org/check-string-substring-another/ to implement is_substring
    // returns true if s1 is substring of s2
    int is_substring(string s1, string s2) {
        //refer
        int M = s1.length();
        int N = s2.length();
        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++)
                if (s2[i + j] != s1[j])
                    break;
            if (j == M) return 1;
            //if (j == M) return true;
                //return i;
        }
        return 0;
    }
};