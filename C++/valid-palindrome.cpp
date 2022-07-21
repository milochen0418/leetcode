class Solution {
    //https://leetcode.com/problems/valid-palindrome
public:
    bool isPalindrome(string s) {
        string r ="";
        for(auto &c:s) if( (c>='A'&&c<='Z') || (c>='a'&&c<='z') || (c>='0'&&c<='9')) r.push_back( c>='A'&&c<='Z'?c-'A'+'a':c);
        //printf("r=%s\n",r.c_str());
        return palindrome(r);
    }
    bool palindrome(string &s){
        int n = s.length();
        for(int i = 0;i<n;i++) {
            int j = n-1-i;
            if(s[i]!=s[j]) return false;
        }
        return true;        
    }
};