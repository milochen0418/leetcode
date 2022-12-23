class Solution {
    //https://leetcode.com/problems/check-if-word-equals-summation-of-two-words
    //https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/discuss/2942339/C%2B%2B-or-simple-4-lines
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        for(string* sp:{&firstWord, &secondWord, &targetWord}) 
            for(int i = 0; i<sp->length();i++) 
                (*sp)[i]=(*sp)[i]-'a'+'0';    
        return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
    }
};