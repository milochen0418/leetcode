class Solution {
    //https://leetcode.com/problems/maximum-repeating-substring
public:
    int maxRepeating(string sequence, string word) {
        int maxk = 0, k = 0, i = 0, n = word.length();
        for(int j = 0;j<sequence.length();j++) {
            char c = sequence[j];
            if(c==word[i]) {
                i=i+1;
                if(i==n) {
                    k+=1;
                    maxk=max(maxk,k);
                    i=0;
                }
            } else {

                if(k>1) 
                    j-=n+1;
                else if(i>0) 
                    j-=1;                
                i=0;
                k=0;
            }            
        }
        return maxk;
    }
};

/* 
Error Case
"bbaabaabaabaaabbbaaabaababbabbaabbabbbabbabbabbbbabaababbbaaaababbbabbaababababbabbbaabbaabbbb"
"bba"

Successful cases
"ababc"
"ab"
"ababc"
"ba"
"ababc"
"ac"
"aaabaaaabaaabaaaabaaaabaaaabaaaaba"
"aaaba"
"bbaa"
"ba"

*/