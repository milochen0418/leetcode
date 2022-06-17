class Solution {
    // https://leetcode.com/problems/arranging-coins
    // article: https://leetcode.com/problems/arranging-coins/discuss/2111204/C%2B%2B-or-binary-search-or-explanation
    
public:
    int arrangeCoins(int n) {
        using ll = long long;
        //int L=1,R=(sqrt(INT_MAX)/500)*708;  //1.414=707/500, 1.416=708/500
        //printf("default R = %d\n", R);
        int L=1,R=(sqrt(n)/500)*708;  //1.414=707/500, 1.416=708/500
        while(L<=R) {
            ll M = (ll)(L + (R-L)/2);
            if( (M*(M+1))/2 <= (ll)n && (ll)n<((M+1)*(M+2))/2 ) return (int)M;
            if( (M*(M+1))/2 <= (ll)n ) L=(int)M+1; else R=(int)M-1;
        } return -1;
    }    

    int arrangeCoinsAnswer1(int n) {
        using ll = long long; 
        ll L = 1,R=(ll)(3*(sqrt(INT_MAX)/2)); //(R*(R+1))/2 = INT_MAX
        while(L<=R) {
            ll t = (ll)n;
            ll M = L+(R-L)/2;
            ll Q1 = (M*(M+1))/2;
            ll Q2 = ((M+1)*(M+2))/2;
            if(Q2>t && t>=Q1) {
                return (int)M;
            } 
            if(t>=Q2)
                L=M+1;
            else
                R=M-1;
        }
        return -1;        
    }


    int arrangeCoinsOld(int n) {
        //  n       n(n+1)
        //Sigma i = -------
        // i=1         2
        using ll = long long;
        ll L = 0, R = n;
        while(L<=R) { 
            ll M = L + (R-L)/2;
            ll v = (M*(M+1))/2;
            if(n > v) {
                L=M+1;
            } else if(n < v) {
                R=M-1;
            } else {
                return M;
            }
        }
        return (int)R;
    }
    //Solve this problem from my solution of this problem
    //https://leetcode.com/problems/sqrtx/
    int mySqrt(int x) {
        using ll = long long;
        ll L = 0, R=x;
        while(L<=R) { 
            ll M = L + (R-L)/2;
            if(x > M*M) {
                L=M+1;
            } else if(x<M*M) {
                R=M-1;
            } else {
                return M;
            }
        }
        return R;
    }
    
};