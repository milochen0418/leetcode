class Solution {
    //https://leetcode.com/problems/sort-the-matrix-diagonally
public:
    vector<vector<int>>& diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> rcs_start;//start rc for each array for sorting
        int m = mat.size(), n = mat[0].size();
        for(int j=0;j<n;j++) rcs_start.push_back({0,j});
        for(int i=1;i<m;i++) rcs_start.push_back({i,0});
        for(auto &rc_begin : rcs_start) {
            vector<vector<int>> rcs;
            vector<int>rc = rc_begin;
            vector<int> v;
            while(1) {
                if(rc[0]<0||rc[1]<0||rc[0]>=m||rc[1]>=n) break;
                rcs.push_back(rc);
                v.push_back(mat[rc[0]][rc[1]]);
                rc[0]+=1;
                rc[1]+=1;
            }
            sort(v.begin(), v.end());
            int k = v.size();
            for(int i=0;i<k;i++) 
                mat[rcs[i][0]][rcs[i][1]] = v[i];
        }
        return mat;
            
    }
};