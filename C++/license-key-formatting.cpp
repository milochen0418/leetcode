class Solution {
    //https://leetcode.com/problems/license-key-formatting
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        string w;
        for(auto &c:s)
            if(c!='-')
                w.push_back( 'z'>=c && c>='a'?c-'a'+'A':c);
        reverse(w.begin(), w.end());
        int n = w.length();
        for(int i = 0; i<n;i++) {
            ans.push_back(w[i]);
            if(i!=n-1 && (i+1)%k==0) 
                ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};