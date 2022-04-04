class Solution {
    //https://leetcode.com/problems/valid-perfect-square/
public:
    bool isPerfectSquare(int num) {
        
        using ll = long long ;
        ll L=1, R=(ll)INT_MAX;
        while(L<=R){
            ll M = L+(R-L)/2;
            if((ll)num>M*M) {
                L=M+1;
            } else if ((ll)num<M*M) {
                R=M-1;
            } else {
                return true;
            }
        }
        return false;
    }
};