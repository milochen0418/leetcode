class Solution {
    //https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
public:
    int minAddToMakeValid(string s) {
        int L=0,cnt=0;
        for(auto &c:s) {
            if(c==')') {
                if(cnt==0) 
                    L++;
                else 
                    cnt--;
            } else {//c=='('
                cnt++;                
            }
        }
        return L+cnt;
    }
};