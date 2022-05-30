class Solution {
    //https://leetcode.com/problems/divide-two-integers
public:
    int divide(int dividend, int divisor) {
        using ll = long long;
        ll d1 =(ll)dividend;
        ll d2 =(ll)divisor;
        ll a = d1/d2;
        if(a>(ll)INT_MAX) return INT_MAX;
        
        return (int)a;
    }
};