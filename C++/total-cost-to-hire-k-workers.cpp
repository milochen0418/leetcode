class Solution {
    //https://leetcode.com/problems/total-cost-to-hire-k-workers/
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //printf("\n\n\n k=%d, candidates=%d\n",k,candidates);
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> minLQ;
        priority_queue<int, vector<int>, greater<int>> minRQ;
        int n = costs.size() ;
        int L = 0, R = costs.size()-1;
        for(int i = 0; i<candidates;i++) {
            minLQ.push(costs[i]);
            L++;
        }
        
        
        int cnt = 0;
        for(int i = n-1;i>=0;i--) {
            if(R<=L) break;
            minRQ.push(costs[i]);
            R--;
            cnt++;
            if(cnt>=candidates) break;
        }
        L-=1;
        R+=1;
        for(int i = 0; i< k;i++) {
            int minL = minLQ.empty()?INT_MAX:minLQ.top();
            int minR = minRQ.empty()?INT_MAX:minRQ.top();
            if(minL <= minR) {
                if(minL == INT_MAX) continue;
                ans += minL;
                minLQ.pop();
                L=L+1;
                if(L<R) {
                    if(L<n) {
                        minLQ.push(costs[L]);
                    }
                }
            } else {
                if(minR == INT_MAX) continue;
                ans += minR;
                minRQ.pop();
                R = R - 1;
                if(L<R) {
                    if(R>=0) {
                        minRQ.push(costs[R]);
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};