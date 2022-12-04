class Solution {
    //https://leetcode.com/problems/circular-sentence/
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if(sentence[0] != sentence[n-1]) return false;
        for(int i = 1 ; i<n;i++)
            if(sentence[i]==' ' && (sentence[i-1] != sentence[i+1]))  return false;
        return true;
    }
};