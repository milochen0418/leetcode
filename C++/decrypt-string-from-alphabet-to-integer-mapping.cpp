class Solution {
    //https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
public:
    string freqAlphabets(string s) {
        string ans = "";
        int n = s.length(), i=0;
        while(i<n) {
            if(i+2<n && s[i+2]=='#') {
                ans.push_back( (s[i]-'0')*10 + (s[i+1]-'0')-1 +'a');
                i+=3;
            } else {
                ans.push_back( s[i]-'0'-1+'a' );
                i+=1;
            }
        }
        return ans;   
    }
};