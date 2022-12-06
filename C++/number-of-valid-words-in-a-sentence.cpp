class Solution {
    //https://leetcode.com/problems/number-of-valid-words-in-a-sentence
public:
    int countValidWords(string sentence) {
        string &s = sentence;
        s.push_back(' ');
        int n = sentence.length(), j= 0,k=0, ans=0;
        for(int i = 0; i<n;i++) {
            while(i<n && s[i]==' ')i++;
            k=j=i;
            while(i<n && s[i]!=' ')i++;
            k = i;
            if(j>=n) break;
            printf("(j,k)=(%d,%d)\n", j,k);
            int is_punctuation_okay = 1;
            int is_no_digit = 1;
            //checking for punctuation
            if(s[j] == '-' || s[k-1] == '-') continue;//case 1: normal case
            if(k-j>=2 && s[k-2]=='-' && ((s[k-1]=='!'||s[k-1]=='.'||s[k-1]==','))) continue;//case 2: case of "-,"
            int hyphen_cnt = 0;
            for(int l = j; l<k;l++) {
                //checking for no digit
                if('0'<=s[l] && s[l]<='9') {
                    is_no_digit=0;
                    break;
                }
                //checking for punctuation
                if(l<k-1 && (s[l] == '!' || s[l] == '.' || s[l] == ',' )) {
                    is_punctuation_okay=0;
                    break;
                }
                if(s[l]=='-')hyphen_cnt++;
            }
            if(is_punctuation_okay == 0) continue;
            if(is_no_digit == 0) continue;
            //checking for hyphen
            if(hyphen_cnt>1) continue;
            ans++;
        }
        return ans;
    }
};