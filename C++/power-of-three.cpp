class Solution {
    //https://leetcode.com/problems/power-of-three
    //article https://leetcode.com/problems/power-of-three/discuss/3028739/C%2B%2B-One-Pass-O(logN) 
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n>0) {
            if(n%3!=0 && n!=1)  return false;
            n/=3;
        }
        return true;
    }
};