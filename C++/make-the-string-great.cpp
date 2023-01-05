class Solution {
    //https://leetcode.com/problems/make-the-string-great
public:
    string makeGood(string s) {
        int n = s.length();
        if(n==0) return "";
        const int v = abs('A'-'a');
        string ans=s;
        do {
            s=ans;
            ans="";
            for(int i = 1; i<=n;i++) 
                if( abs(s[i] - s[i-1]) == v) 
                    i++;
                else 
                    ans.push_back(s[i-1]);
        } while(ans!=s);
        ans = ans.c_str();
        return ans;
    }
};