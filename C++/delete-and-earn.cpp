class Solution {
    //https://leetcode.com/problems/delete-and-earn/
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> cost;
        for(auto &i:nums) cost[i]+=i;
        unordered_set<int> set;
        for(auto &i:nums) set.insert(i);
        vector<int> A;
        for(auto &i:set) A.push_back(i);
        sort(A.begin(), A.end());
        
        //Right now we have the cost[0..n]... 
        //We start to get value from cost[0] or cost[1].. 
        //every time we select i, then we go up step i+2 because we cannot select adjenct 
        //cost. If we are not select i, then wwe can go up step i+1.
        //Keep going and stop if i>=n. 
        //In this process,  we want to find which is the maximum total cost we can get.
        vector<int> dp = vector<int>(A.back()+1, -1);
        function<int (int)> sol = [&](int i) {
            int n = dp.size();
            if(i>=n) return 0;
            if(dp[i] != -1) return dp[i];
            int cost_i = cost.find(i)==cost.end()?0:cost[i];
            dp[i] = max(cost_i + sol(i+2), sol(i+1));
            return dp[i];
        };
        int ans = sol(0);
        return ans;
    }
};