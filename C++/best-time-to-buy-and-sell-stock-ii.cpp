class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
public:
    int maxProfit(vector<int>& prices) {
        //Idea 2, every valley to Peak but only add on value
        //in the end of valley (the pointer is in previous of rising edge)
        int ans = 0, n = prices.size();
        int v = 0;
        for(int i =1;i<n;i++) {
            if(prices[i] - prices[i-1] >0) {
                v+=prices[i] - prices[i-1];
            } else {
                if(i+1<n && prices[i+1] - prices[i] > 0) {
                    //The point in the valley
                    ans+=v;
                    v = 0;
                } else {
                    //case of keeping in the falling edge
                }
            }
        }
        ans+=v;
        return ans;
    }

    int maxProfit_v03(vector<int>& prices) {
        //Idea 2, every valley to Peak
        int ans = 0, n = prices.size();
        int v = 0;
        for(int i =1;i<n;i++) {
            if(prices[i] - prices[i-1] >0) { //rising edge
                v+=prices[i] - prices[i-1];
            } else { //peak arrive or in the falling
                ans+=v;
                v = 0;
            }
        }
        ans+=v;
        return ans;
    }
    int maxProfit_v02(vector<int>& prices) {
        //Idea, just sell it in every rise edge
        int ans = 0, n = prices.size();
        for(int i =1;i<n;i++) {
            int v = prices[i] - prices[i-1];
            if(v>0) ans+=v;
        }
        return ans;
    }

    int maxProfit_v01(vector<int>& prices) {
        vector<int>& a = prices;
        int n = a.size(), ans=0;
        for(int i = 1; i<n;i++) if(a[i]>a[i-1])ans+=a[i]-a[i-1];
        return ans;
    }
};