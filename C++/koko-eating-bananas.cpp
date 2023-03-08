class Solution {
    //https://leetcode.com/problems/koko-eating-bananas
public:
    typedef long long ll;
    int minEatingSpeed(vector<int>& piles, int h) {
        //binary search function but with dynamic programming in checking function
        int n = piles.size();
        unordered_map<ll,int> mp;//dyanmic programming for check()
        function<ll(int)> check = [&](int k){
            if(mp.find(k) != mp.end()) return mp[k];
            ll times = 0;
            for(int i = 0; i<n; i++) {
                int p = piles[i];
                int acc = p/k + ((p%k)!=0);
                times+=acc;
            }
            return mp[k] = times;
        };
        int maxv = 0;
        for(auto &p:piles) 
            maxv=max(p,maxv);
        
        int L = 1, R=maxv;
        while(L<=R) {
            int M = R-(R-L)/2;
            //printf("[%d,%d]->M=%d\n",L,R,M);
            if(check(M)<=h && (M-1<1 ||check(M-1)>h)) return M;
            if(check(M)<=h)
                R=M-1;
            else
                L=M+1;
        }
        return -1;
    }

    int minEatingSpeed_v02(vector<int>& piles, int h) {
        //Binary Search solution by checking function
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
        while(L<=R) {
            int M = R-(R-L)/2;
            //printf("[%d,%d]->M=%d\n",L,R,M);
            if(check(M)<=h && (M-1<1 ||check(M-1)>h)) return M;
            if(check(M)<=h)
                R=M-1;
            else
                L=M+1;
        }
        return -1;
    }

    int minEatingSpeed_v01(vector<int>& piles, int h) {
        //TLE by checking function
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