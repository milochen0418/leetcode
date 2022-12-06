class Solution {
    //https://leetcode.com/problems/time-needed-to-buy-tickets
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        //Time complexity : O(N)
        int v = tickets[k];
        int ans= 0, n = tickets.size();;
        for(int i = 0; i<=k;i++) {
            ans+=min(tickets[i],v);
        }
        for(int i = k+1;i<n;i++) {
            ans+=min(tickets[i],v-1);
        }
        return ans;
    }
};