class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
public:
    int maxProfit(vector<int>& prices) {
        vector<int>& a = prices;
        int n = a.size(), ans=0;
        for(int i = 1; i<n;i++) if(a[i]>a[i-1])ans+=a[i]-a[i-1];
        return ans;
    }
};