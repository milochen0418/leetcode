class Solution {
    //https://leetcode.com/problems/circular-sentence/
    //article https://leetcode.com/problems/circular-sentence/discuss/2875247/C%2B%2B-or-easy-or-space-O(1)-time-O(N)-or-no-split-or-explanation
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if(sentence[0] != sentence[n-1]) return false;
        for(int i = 1 ; i<n;i++)
            if(sentence[i]==' ' && (sentence[i-1] != sentence[i+1]))  return false;
        return true;
    }
};