class Solution {
    //https://leetcode.com/problems/check-if-word-equals-summation-of-two-words
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        for(string* sp:{&firstWord, &secondWord, &targetWord}) 
            for(int i = 0; i<sp->length();i++) 
                (*sp)[i]=(*sp)[i]-'a'+'0';    
        return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
    }
};