class Solution {
    //https://leetcode.com/problems/take-gifts-from-the-richest-pile/
public:
    long long pickGifts(vector<int>& gifts, int k) {
        typedef long long ll;
        priority_queue<ll> maxQ;
        for(auto &i: gifts) maxQ.push((ll)i);
        for(int i = 0; i<k;i++) {
            ll e = maxQ.top(); maxQ.pop();
            e = sqrt(e);
            maxQ.push(e);
        }
        
        ll ans = 0;
        while(!maxQ.empty()) {
            ans+=maxQ.top();
            maxQ.pop();
        }
        return ans;
        
    }
};