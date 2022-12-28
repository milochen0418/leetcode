class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxQ;
        for(auto &p:piles) maxQ.push(p);
        
        while( k>0 && !maxQ.empty() ) {
            int v = maxQ.top();
            maxQ.pop();
            v-=v/2;
            maxQ.push(v);
            k--;
        }
        
        int ans = 0; 
        while(!maxQ.empty()) {
            ans+=maxQ.top();
            maxQ.pop();
        }
        return ans;
    }
};