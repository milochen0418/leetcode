class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    //article https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1735410/C%2B%2B-or-O(N)-or-Step-by-Step-from-O(N2)-to-O(N)-or-!DP
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_gap = 0, minv = prices[0];
        for(int i = 1; i<n;i++) {
            minv = min(minv, prices[i]);
            max_gap = max(max_gap, prices[i] - minv);
        }   
        return max_gap;
    }
};