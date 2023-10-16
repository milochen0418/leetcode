class Solution {
    //https://leetcode.com/problems/sort-vowels-in-a-string
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        string vs;
        for(auto &c: s) 
            if(vowels.find(c) != vowels.end()) 
                vs.push_back(c);
        sort(vs.begin(), vs.end());
        
        int n = s.length(), j=0;
        for(int i = 0; i<n;i++) 
            if(vowels.find(s[i]) != vowels.end()) 
                s[i] = vs[j++];
        return s;
    }
};