class Solution {
    //https://leetcode.com/problems/reverse-vowels-of-a-string/
public:
    string reverseVowels(string s) {
        vector<int> v;//save all idx with vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o','u','A','E','I','O','U'};
        for(int i = 0; i<s.length();i++) 
            if(vowels.find(s[i]) != vowels.end()) 
                v.push_back(i);
        int L=0,R=v.size()-1;
        while(L<R) swap(s[v[L++]], s[v[R--]]);
        return s;        
    }
};