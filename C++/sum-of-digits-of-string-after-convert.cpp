class Solution {
    //https://leetcode.com/problems/sum-of-digits-of-string-after-convert
public:
    int getLucky(string s, int k) {
        unordered_map<char,int> sump;
        for(char i='a';i<='z';i++) {
            int q = (i-'a')+1;
            sump[i] = q%10 + q/10;
        }
        int ans = 0;
        for(int ik = 1; ik<=k;ik++) {
            if(ik==1) {
                for(auto &c:s) {
                    ans+=sump[c];
                }
            } else {//case ik>=2
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