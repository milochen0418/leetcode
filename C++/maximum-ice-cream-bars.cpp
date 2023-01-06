class Solution {
    //https://leetcode.com/problems/maximum-ice-cream-bars
public:
    int maxIceCream(vector<int>& costs, int coins) {
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