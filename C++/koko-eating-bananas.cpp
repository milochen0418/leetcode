class Solution {
    //https://leetcode.com/problems/koko-eating-bananas
public:
    typedef long long ll;
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        function<ll(int)> check = [&](int k){            
            ll times = 0;
            for(int i = 0; i<n; i++) {
                int p = piles[i];
                int acc = p/k + ((p%k)!=0);
                times+=acc;
            }
            return times;
        };
        int maxv = 0;
        for(auto &p:piles) 
            maxv=max(p,maxv);
        
        int L = 1, R=maxv;
        
        for(int i = L;i<=R;i++) 
            if(check(i)<=(ll)h) return i;
        
        return -1;
    }
};