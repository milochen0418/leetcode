class Solution {
    //https://leetcode.com/problems/count-binary-substrings
public:
    int countBinarySubstrings(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0;i<n-1;i++) {
            char L = s[i];
            int Lcnt = 0, j = i;
            while(j<n && s[j++]==L) Lcnt++;
            j-=1;
            while(j<n && s[j++]!=L) {
                Lcnt--;
                if(Lcnt==0) break;
            }
            if(Lcnt==0) ans++; 
        }
        return ans;
    }
};