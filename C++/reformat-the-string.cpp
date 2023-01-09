class Solution {
    //https://leetcode.com/problems/reformat-the-string
public:
    string reformat(string s) {
        string A,B;
        for(auto &c:s) (('0'<=c&&c<='9')?A:B).push_back(c);
        if( abs((int)A.length()- (int)B.length()) >1 )return "";
        if(B.length()>A.length()) swap(A,B);
        for(int i =0;i<s.length();i++) s[i]=(i%2==0)?A[i/2]:B[i/2];
        return s;
    }
};