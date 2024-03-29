class Solution {
    //https://leetcode.com/problems/find-champion-i
    //article https://leetcode.com/problems/find-champion-i/discuss/4279584/C%2B%2B-or-One-Pass-O(N2)
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int j = 0; j<n; j++) {
            int found = 1;
            for(int i = 0; i<n; i++) {
                if(i!=j && grid[i][j]!=0) {
                    found=0;
                    break;
                }
            }
            if(found) return j;
        }
        return 0;
    }
};