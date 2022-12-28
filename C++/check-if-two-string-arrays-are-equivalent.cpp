class Solution {
    //https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int sum1=0, sum2=0;
        for(auto &s:word1) sum1+=s.length();
        for(auto &s:word2) sum2+=s.length();
        if(sum1!=sum2) return false;
        if(sum1==0)return true;
        int n = sum1, cnt=0;
        int i1=0,j1=0,i2=0,j2=0;
        do {
            if(word1[i1][j1] != word2[i2][j2]) return false;
            if(++j1==word1[i1].length()) i1=i1+1,j1=0;
            if(++j2==word2[i2].length()) i2=i2+1,j2=0;            
            cnt++;
        } while(cnt<n);
        return true;
    }
};