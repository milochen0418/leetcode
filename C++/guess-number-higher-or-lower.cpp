/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
    //https://leetcode.com/problems/guess-number-higher-or-lower/
public:
    int guessNumber(int n) {
        int L=1, R=n;
        while(L<=R) {
            int M = L + (R-L)/2;
            int v = guess(M);
            if(v>0) {
                L=M+1;
            } else if(v<0) {
                R=M-1;    
            } else {
                return M;
            }
        }
        return -1;
    }  
};