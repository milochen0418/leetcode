class Solution {
    //https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a>0 || b>0 || c>0) {
            int ar = a%2, br = b%2, cr = c%2;
            if(cr==0) 
                ans+=(ar+br);
            else //cr==1            
                ans+=(0==ar+br);
            a/=2;
            b/=2;
            c/=2;
        }
        return ans;
    }
};