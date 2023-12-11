class Solution {
    //https://leetcode.com/problems/jump-game-iii
public:
    bool canReach(vector<int>& arr, int start) {
        bool ans = false;
        int n = arr.size();
        unordered_set<int> visited; 
        unordered_map<int,unordered_set<int>> mp;
        for(int i = 0; i<n; i++) {
            if(i+arr[i] < n) mp[i].insert(i+arr[i]);
            if(i-arr[i] >=0) mp[i].insert(i-arr[i]);
        }
        /*
        for(int i = 0; i<n;i++) {
            printf("%d: ",i);
            for(auto &j:mp[i]) {
                printf("%d,", j);
            }
            printf("\n");
        }*/
        function<void(int)> dfs = [&](int idx) {
            //printf("%d, ");
            if(idx<0 || idx>=n) return;
            if(visited.find(idx) != visited.end()) return; 
            visited.insert(idx);
            if(arr[idx] == 0) ans = true;
            for(auto &i: mp[idx]) dfs(i);
        };
        dfs(start);
        return ans;
    }
};