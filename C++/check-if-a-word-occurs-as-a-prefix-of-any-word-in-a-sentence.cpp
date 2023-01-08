class Solution {
    //https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), m = searchWord.length(), idx=1,j=0;
        for(int i = 0;i<n;) {
            if(sentence[i]==' ') {
                idx++;
                j=0;
            } else {
                if(sentence[i]==searchWord[j++]) {
                    if(j==m) return idx;
                } else {
                    while(i+1<n && sentence[i+1]!=' ')i++;
                }
            }
            i++;
        }   
        return -1;
    }
};