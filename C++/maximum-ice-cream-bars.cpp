class Solution {
    //https://leetcode.com/problems/maximum-ice-cream-bars
    //Study Counting Sort https://leetcode.com/explore/learn/card/sorting/695/non-comparison-based-sorts/4437/
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //sorting
        int ans = 0;
        sort(costs.begin(),costs.end());
        for(auto &i: costs) {
            coins -= i;
            if(coins>=0) 
                ans++;
            else
                break;
        }
        return ans;
    }

    int maxIceCream_v01(vector<int>& costs, int coins) {
        //priority_queue
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for(auto &i:costs) minQ.push(i); 
        while(!minQ.empty()) {
            coins -= minQ.top();
            minQ.pop();
            if(coins >=0) 
                ans++;
            else 
                break;
        }
        return ans;
    }
};