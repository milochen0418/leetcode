/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    //https://leetcode.com/problems/read-n-characters-given-read4
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int sum = 0;
        char buf4[4];
        int len=0;
        while((len = read4(buf4))>0) {
            for(int i = 0;i<len;i++) {
                *buf = buf4[i];
                buf++;
                sum++;
                if(sum==n) return n;
            }
        }
        return sum;
    }
};