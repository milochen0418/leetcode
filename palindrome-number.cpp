class Solution {
    //https://leetcode.com/problems/palindrome-number
public:
    bool isPalindrome(int x) {
        if (x < 0 ) return false;
        int h = 1;
        //while(x >= 10*h) { <- h*10 will overflow
        while(x/h >= 10) {
            h = h*10;
        }
        //=>> x < h*10, so same digit number
        //=> x= 12321 -> h= 10000
        
        while(x>0) {
            if(x/h != x%10) return false; // 12321/10000=1(left-most), 12321%10=1(right-most)
            x = x % h; //-> 2321
            x = x / 10;//-> 232
            h = h / 100;//->100
        }
        return true;
    }
};