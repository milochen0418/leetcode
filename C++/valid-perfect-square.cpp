class Solution {
    //https://leetcode.com/problems/valid-perfect-square/
public:
    bool isPerfectSquare(int num) {
        int L=1,  R= sqrt( INT_MAX-1 );
        while(L<=R) {
            int M = (L + (R-L)/2);
            if(M*M == num) {
                return true;
            } else if(M*M > num) {
                R = M-1;
            } else { //case MM < num
                L = M+1;
            }
        }
        return false;
    }

};