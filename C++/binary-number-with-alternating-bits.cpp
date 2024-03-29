class Solution {
    //https://leetcode.com/problems/binary-number-with-alternating-bits
    //article https://leetcode.com/problems/binary-number-with-alternating-bits/discuss/3081130/C%2B%2B-2-approaches-O(1)-and-O(logN)
public:
    bool hasAlternatingBits(int n) {
        //O(1)
        return ((n/4 & n)== n/4 && (n/2&n)==0);
    }
    bool hasAlternatingBits_(int n) {
        //O(Log(N))
        int prev = -1;
        while(n>0) {
            if(n%2==prev) {
                return false;
            } else {
                prev=n%2;
            }
            n/=2;
        }
        return true;
    }
};