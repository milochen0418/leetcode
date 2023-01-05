class Solution {
    //https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
    //article https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/discuss/3002864/C%2B%2B-or-O(N)-Monotonic-Stack
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> stk;
        int n = prices.size();
        vector<int> ans = prices;
        for(int i = 0; i<n;i++) {
            if(stk.empty() || prices[stk.back()] < prices[i]) {
                stk.push_back(i);
            } else {
                while(!stk.empty() && prices[stk.back()] >= prices[i]) {
                    prices[stk.back()]-=prices[i];
                    stk.pop_back();
                }
                stk.push_back(i);
            }
            printf("i=%d, stk = ", i);
            for(auto &e:stk) {
                printf("%d, ",e);
            }
            printf("\n");
        }
        return prices;
    }

    vector<int> finalPrices_v01(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        for(int i = 0; i<n;i++) 
            for(int j = i+1; j<n;j++) 
                if(prices[j]<=prices[i]) {
                    ans[i]-=prices[j];
                    break;                    
                }
        return ans;
    }
};