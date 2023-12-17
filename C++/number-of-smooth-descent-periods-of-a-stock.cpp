class Solution {
    //https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock
public:
    long long getDescentPeriods(vector<int>& prices) {
        typedef long long ll;
        ll ans=0;
        prices.push_back(-1); //-1 is dummy element
        int n = prices.size();
        int L=0,R=0;
        while(L<=R && R<n) {
            if(L==R) {
                R=R+1;
            } else if(prices[R]==prices[R-1]-1){
                R=R+1;
            } else {
                int r = R-1;
                int l = L;
                ll m = r-l+1; //figure out the number of element for [L..R-1]
                //[5,4,3,2,1] make (5*6)/2, [5,4,3,2] make (4*5)/2 ... 
                ans+=(m*(m+1))/2;
                ans-=m; //clean each independent only one element in [L..R-1]
                L=R;
            }
        }
        ans+=(n-1); //count up each indepdent only one elemnt
        return ans;
    }
};