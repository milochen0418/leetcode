class Solution {
    //https://leetcode.com/problems/check-knight-tour-configuration/
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        unordered_map<int,vector<int>> mp;
        int n = grid.size();
        for(int i = 0;i <n;i++) 
            for(int j = 0;j<n;j++) 
                mp[grid[i][j]] = {i,j};
        //return false;
        for(int k = 0; k < n*n;k++) 
            if(mp.find(k) == mp.end()) return false;
        vector<int> prev=mp[0];
        for(int k = 1;k<n*n;k++) {
            vector<int> curr = mp[k];
            int a = abs(curr[0] - prev[0]);
            int b = abs(curr[1] - prev[1]);
            if((a==1 && b==2) || (a==2 && b==1)) {
                prev=curr;    
            } else {
                return false;
            }
        }
        return true;
    }
};