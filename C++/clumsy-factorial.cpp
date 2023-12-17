
class Solution {
    //https://leetcode.com/problems/clumsy-factorial
    //article https://leetcode.com/problems/clumsy-factorial/discuss/4415320/C%2B%2B-or-Recursive-Approach-O(N)-with-explain
public:
    int clumsy(int N) {
        /*
        10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
        (10*9/8) + 7 -1*(6 * 5 / 4)+3 -1*(2 * 1); 
        */
        function<double(double)> sol = [&](double n) -> double {
            if(n<=1.1f) return 0.0f;
            double val = n;
            if(abs(val-(double)N) > 0.5f) val = val*-1;
            val = val * (n-1>0.9f?n-1:1.0f);
            val = val / (n-2>0.9f?n-2:1.0f);
            val = val + (n-3>0.9f?n-3:0.0f);
            //printf("%f\n", val);
            val = val + round(sol(n-4));
            return val;
        };
        double ans = sol((double)N);
        //printf("sol(N=%d) = %f\n",N,ans);
        ans = round(ans);
        return (int)ans;
    }
};

