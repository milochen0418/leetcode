class Solution {
    //https://leetcode.com/problems/make-three-strings-equal
    //article https://leetcode.com/problems/make-three-strings-equal/discuss/4343407/C%2B%2B-or-simple-4-lines-O(N)-solution
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.length(), n2=s2.length(), n3=s3.length();
        int L=0, H = min(n1,min(n2,n3));
        for(L = 0; L<H; L++) if(s1[L] != s2[L] ||  s2[L] != s3[L]) break;
        return L==0?-1:(n1-L) + (n2-L) +(n3-L);
    }
};