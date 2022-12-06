class Solution {
    //https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n = cost.size(), ans = 0;
        while(cost.size() % 3 !=0)cost.push_back(0);
        for(int i = 0; i<n;i+=3) ans+=(cost[i]+cost[i+1]);
        return ans;
    }
};