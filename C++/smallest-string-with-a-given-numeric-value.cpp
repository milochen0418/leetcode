class Solution {
    //https://leetcode.com/problems/smallest-string-with-a-given-numeric-value
public:
    string getSmallestString(int n, int k) {
        
        // a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z 
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
        
        //case n=3, k=27 (k-n=24 , k+n=30) = 25*1 + 5 = 
        //27 = 26 + 1 but n = 3, => 25+1+1 is answer
        //0+0+24 
        
        //case n=5, k=73 (k-n=68, k+n=78) = 25*3 + 3
        //73 = 26*2 + 21 but n = 5 -> 1+1+19+2*26        
        //0+0+18+25+25 = 68
        
        //case n=4, k=54  (k-n = 50) aazz
        //0+0+25+25
        
        int total = k-n;
        int z_cnt = total / 26;
        int middle_val = total % 26;
        int a_cnt = n-z_cnt-(middle_val!=0);
        
        
        
        
        
        
        
        
    }
};