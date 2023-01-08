class Solution {
    //https://leetcode.com/problems/maximal-score-after-applying-k-operations/
public:
    //https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
    //q = 1 + ((x - 1) / y); // if x != 0
    //e.g. q = 1+((10-1)/3) = 1+(9/3) = 1+3 = 4
    long long maxKelements(vector<int>& nums, int k) {
        typedef long long ll;
        ll ans = 0;
        priority_queue<ll> maxQ;
        for(auto &i: nums) maxQ.push(i);
        while(k>0 && !maxQ.empty()) {
            
            ll e = maxQ.top();
            
            maxQ.pop();
            ll q = 1 + ((e - 1) / 3);
            //printf("k:%d -> %ld ->q=%ld\n", k, e,q );
            if(q>=1) maxQ.push(q);
            ans+=e;   
            k--;
        }
        return ans;
        
    }
};