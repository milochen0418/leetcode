class Solution {
    //https://leetcode.com/problems/count-total-number-of-colored-cells/
public:
    typedef long long ll;
    long long coloredCells(int n) {
        //n=1 -> 1
        //n=2 -> 1 3 1
        //n=3 -> 1 3 5 3 1
        //n=4 -> 1 3 5 7 5 3 1
        //n=5 -> 1 3 5 7 9 7 5 3 1
        
        //1+3+5+7+9= 25 <-> 5*(1+9)/2
        //1+3+5+7 = 16 <-> 4*(1+7)/2 = 16
        
        //1+3+...+(n*2-1) <-> n*(1+ (n*2-1) )/2
        //1+...+(n*2-3) <-> (n-1)*(1+ (n*2-3) )/2
        
        if(n==1)return 1;
        ll k = n;
        ll item1 = ((k)*(1+(k*2-1) ))/2;
        ll item2 = ((k-1)*(1+ (k*2-3) ))/2;
        return item1+item2;
            
    }
};