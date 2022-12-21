class Solution {
    //https://leetcode.com/problems/sum-of-digits-of-string-after-convert
public:
    int getLucky(string s, int k) {
        vector<int> sumv=vector<int>(256,0);
        for(char i='a';i<='z';i++) {
            int q = (i-'a')+1;
            sumv[i]=q%10 + q/10;
        }
        int ans = 0;
        for(int i = 1;i<=k;i++) {
            if(i==1) {
                for(auto &c:s) {
                    ans+=sumv[c];
                }
            } else {//case i>=2
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