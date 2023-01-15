class Solution {
    //https://leetcode.com/problems/high-five/
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int>> mp;  //mapping ID to maxQ
        for(auto &item: items) mp[item[0]].push(item[1]);
        vector<vector<int>> ans;
        for(auto &[id,maxQ]: mp) {
            int sum = 0;
            for(int i = 0;i<5;i++) {
                sum+=maxQ.top();
                maxQ.pop();
            }
            ans.push_back({id, sum/5});
        }
        sort(ans.begin(), ans.end(), [](auto &lhs, auto &rhs){
            return lhs[0]<rhs[0];
        });
        return ans;
        
    }
};