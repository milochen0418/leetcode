class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    //article https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1735410/C%2B%2B-or-O(N)-or-Step-by-Step-from-O(N2)-to-O(N)-or-!DP
    //article II https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/2940935/C%2B%2B-or-3-Pass-and-1-Pass-approach
public:
    int maxProfit(vector<int>& prices) {
        /*
        The maximum prices difference must come from one forward price and 
        some backward price.
        in all prices[], the best difference must contain a backward price that in prices.
        In view of backward price, the best solution it can make is to find out which 
        is the lowest prices in the forward side 
        */
        
        int ans = 0, minv = prices[0], n = prices.size();
        for(int i = 1;i<n;i++) {
            ans = max(ans, prices[i]-minv);
            minv = min(minv,prices[i]);
        }
        return ans;
    }
    int maxProfit_v01(vector<int>& prices) {
        int n = prices.size();
        int max_gap = 0, minv = prices[0];
        for(int i = 1; i<n;i++) {
            minv = min(minv, prices[i]);
            max_gap = max(max_gap, prices[i] - minv);
        }   
        return max_gap;
    }

    int maxProfit_3pass(vector<int>& prices) {        
        //for each min point i, find out the j>i s.t. prices[j] is maximum in prices[i..n-1]  
        int n = prices.size(), ans = 0;
        vector<int> minp = vector<int>(n, prices[0]);
        vector<int> maxp = vector<int>(n, prices[n-1]);        
        for(int i = 1; i<n;i++) minp[i] = min(prices[i], minp[i-1]);
        for(int i = n-2;i>=0;i--) maxp[i] = max(prices[i], maxp[i+1]);
        for(int i = 0; i<n;i++) ans = max(ans, maxp[i]-minp[i]);
        return ans;
    }


};