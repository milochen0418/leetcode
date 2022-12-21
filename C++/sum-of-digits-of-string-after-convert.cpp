class Solution {
    //https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
public:
    int getLucky(string s, int k) {
        unordered_map<char,int> mp;
        unordered_map<char,int> sump;
        for(char i='a';i<='z';i++) {
            mp[i] = (i-'a')+1;
            sump[i] = mp[i]%10 + mp[i]/10;
        }
        int ans = 0;
        for(int ik = 1; ik<=k;ik++) {
            if(ik==1) {
                for(auto &c:s) {
                    ans+=sump[s[ik]];
                }
            } else {//case ik>=3
                int tmp = ans;
                ans = 0; 
                while(tmp>0) {
                    ans+=tmp%10;
                    tmp/=10;
                }
            }
        }
        return ans;
    }
};