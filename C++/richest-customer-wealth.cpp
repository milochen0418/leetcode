class Solution {
    //https://leetcode.com/problems/richest-customer-wealth
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0; 
        for(auto& c:accounts) 
            max_wealth = max(max_wealth, accumulate(c.begin(), c.end(), 0));
        return max_wealth;
    }
};