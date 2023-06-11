class Solution {
    //https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/
public:
    string smallestString(string s) {
        // XXXXXaaaOOOOaaa  --- case 1
        // aaaXXXXXXXaaaOOOOaaa  --- case 2
        // aaaaaaaaa --- case 3
        int n = s.length();
        //case 3
        int all_a = 1;        
        for(auto &c:s) {
            if(c!='a') {
                all_a=0;
                break;
            }
        }
        if(all_a == 1) {
            s[n-1] = 'z';
            return s;
        }
        //case 1
        if(s[0]!='a') {
            for(int i =0;i<n;i++) {
                if(s[i]!='a') {
                    s[i] = s[i]-1;
                } else {
                    break;
                }
            }
            return s;
        } 
        
        //csae 2
        
        int L = 0;
        for(int i = 0; i<n;i++) {
            if(s[i]!='a') {
                L = i;
                break;
            }
        }
        for(int i = L;i<n;i++) {
            if(s[i]!='a') {
                s[i] = s[i] - 1;
            } else {
                break;
            }
        }
        return s;
        
        
    }
};