class Solution {
public:
    /*
    Observation 
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 <-- Input
0,2,3,4,5,5,7,6,6,07,11,07,13,09,08 <-- Output
    */
    int minSteps(int n) {
        if(n==1) return 0;
        int ans = 0;
        int i = 2;
        while( n > 1 ) {
            while( n%i == 0 ) {
                ans+=i;
                n = n/i;
            }
            i = i+1;
        }
        return ans;
    }
        
    
};