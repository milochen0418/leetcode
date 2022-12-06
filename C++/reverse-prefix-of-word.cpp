class Solution {
    //https://leetcode.com/problems/reverse-prefix-of-word
public:
    string reversePrefix(string word, char ch) {
        int L=0,R=0,n=word.size();
        while(R<n && word[R]!=ch)R++;
        if(R==n) return word;
        while(L<R) swap(word[L++],word[R--]);
        return word;
    }
};