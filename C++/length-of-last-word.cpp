class Solution {
    //https://leetcode.com/problems/length-of-last-word
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int start=0;
        int end=n-1;
        for(int i=n-1;i>=0;i--) {
            if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
                end = i;
                break;
            }
        }
        for(int i = end; i>=-1;i--) {
            if(i==-1 || s[i]==' ' ) {
                start = i+1;
                break;
            }
        }
        return end-start+1;
    }
};