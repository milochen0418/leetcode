class Solution {
    //https://leetcode.com/problems/maximum-candies-allocated-to-k-children
public:
    using ll = long long ;
    int maximumCandies(vector<int>& a, ll k) {

        int L = 0; 
        //int R = 1000000000;
        int R = 1+*max_element(a.begin(),a.end());
        while(L<R) {
            int M = L + (R-L)/2;
            //cout<<"(L,R)="<<L<<","<<R<<" -> M="<<M<<"\n";
            
            if(M==0) return 0;
            if(check(a,k,M) && !check(a,k,M+1)){
                return M;
            } else {
                if(check(a,k, M+1)==true) {
                    L=M+1;
                } else {
                    R=M;
                }
            }
        }
        return R;
    }
    
    bool check(vector<int>& a, ll k, int m) {
        ll sum = 0;
        for(auto& i:a) sum+= i/m;
        return sum>=k;
    }

};