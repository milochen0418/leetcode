class Solution {
    //https://leetcode.com/problems/sqrtx/
public:
    int mySqrt(int x) {
        const int MAX = 46340; //sqrt of INT_MAX;
        int L = 0, R=MAX;
        while(L<=R) {
            int M = L + (R-L)/2;
            if( M+1>MAX || (M+1)*(M+1) > x && x>=M*M) return M;
            if(x<M*M) R=M-1; else L=M+1;
        }
        return -1;
    }

    int mySqrtAnswer2(int x) {
        using ll = long long;
        int L = 0, R = x;
        while(L<=R) {
            ll M = L+(R-L)/2;
            if( (M+1)*(M+1)>(ll)x && (ll)x>=M*M) {
                return (int)M;
            }
            if(M*M < (ll)x) 
                L=M+1;
            else
                R=M-1;
        }
        return -1;
    }

    int mySqrtOld(int x) {
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