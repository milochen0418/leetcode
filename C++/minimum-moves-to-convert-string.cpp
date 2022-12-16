class Solution {
    //https://leetcode.com/problems/minimum-moves-to-convert-string/
public:
    /* 
    Case Analysis
    OOXOXOO
    XXOX
    XX XOX XX
    XXOXOXOXX
    */
    int minimumMoves(string s) {
        int ans = 0,n=s.length();
        for(int i = 0;i<n-2;i++) {
            ans+=true==clear3(i,s);
        }
        for(int i = 0;i<n-2;i++) {
            ans+=true==clear2(i,s);
        }
        
        for(int i = 0;i<n;i++) {
            ans+=s[i]=='X';
        }
        return ans;
    }
    
    bool clear3(int i,string& s) {
        if(i+2>=s.length()) return false;
        if(s[i]!='X' || s[i+1]!='X' || s[i+2]!='X') return false;
        s[i]=s[i+1]=s[i+2]='O';
        return true;
    }
    
    bool clear2(int i,string& s) {
        if(i+2>=s.length()) return false;
        int cnt = 0;
        cnt+=s[i]=='X';
        cnt+=s[i+1]=='X';
        cnt+=s[i+2]=='X';
        if(cnt<2) return false;
        s[i] = s[i+1] = s[i+2] = 'O';
        return true;
    }
    //Key idea is to delete XXX first. And then try to delete XXO first and XOX letter
    //Error Case 
    //"XOXXOXXXX"
};