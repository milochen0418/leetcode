class Solution {
    //https://leetcode.com/problems/complement-of-base-10-integer
    //article https://leetcode.com/problems/complement-of-base-10-integer/discuss/3057347/C%2B%2B-One-Pass-O(logN)-8-lines
public:
    int bitwiseComplement(int n) {
        int ans=0, base = 1;
        if(n==0) return 1;
        while(n>0) {
            ans+=base*(n%2==0);
            base*=2;
            n/=2;
        }
        return ans;
    }
};