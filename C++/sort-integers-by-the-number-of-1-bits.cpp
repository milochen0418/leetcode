class Solution {
    //https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
    //refer article https://www.geeksforgeeks.org/count-set-bits-in-an-integer/ to implement fast bit 1 count
public:

    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(), a.end(), [](auto& lhs, auto& rhs){
            int va=__builtin_popcount(lhs);
            int vb=__builtin_popcount(rhs);
            return (va==vb)?lhs<rhs:va<vb;
        });
        return a;
    }

    int tbl[256];//Bits Set Table 256
    int countSetBits(int n) {
        return tbl[n&0xff] +tbl[(n>>8)&0xff] +tbl[(n>>16)&0xff] +tbl[n>>24];
    }    
    vector<int> sortByBitsVer01(vector<int>& a) {
        //init table
        tbl[0] = 0;
        for (int i=0; i<256; i++) tbl[i] = (i&1) + tbl[i/2];

        sort(a.begin(), a.end(), [&](auto& lhs, auto& rhs){
            int va=countSetBits(lhs);
            int vb=countSetBits(rhs);
            return (va==vb)?lhs<rhs:va<vb;
        });
        return a;
    }
};