class Solution {
    https://leetcode.com/problems/clumsy-factorial///
public:
    int clumsy(int N) {
        /*
        10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
        (10*9/8) + 7 -1*(6 * 5 / 4)+3 -1*(2 * 1); 
        */
        function<int(int)> sol = [&](int n)-> int {
            if(n<1) return 0;
            int val = n;
            if(N!=n) val = val * -1;
            int b = (n-1>=1)?n-1:1;
            int c = (n-2>=1)?n-2:1;
            int d = (n-3>=1)?n-3:0;
            val = ((val * b)/c)+d;
            val = val + sol(n-4);
            return val;
        };
        return sol(N);        
    }

};