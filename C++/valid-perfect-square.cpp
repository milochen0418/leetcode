class Solution {
    //https://leetcode.com/problems/valid-perfect-square/
    //article https://leetcode.com/problems/valid-perfect-square/discuss/2102470/C%2B%2B-or-simple-solution-using-int-type-only
public:
    bool isPerfectSquare(int num) {
        int L=1,  R=sqrt( INT_MAX );
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