class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
public:
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN, held = INT_MIN, reset = 0;
        for(auto price:prices) {
            int pre_sold = sold;
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, pre_sold);
        }
        return max(sold, reset);
    }
};