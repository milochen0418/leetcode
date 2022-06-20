class Solution {
    //https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int min_idx=-1, val=INT_MIN;
        vector<vector<int>> v = vector<vector<int>>(m,vector<int>(2,0));
        for(int i = 0; i < m; i++) {
            vector<int>& a = mat[i];
            int L = -1, R = n-1, M;
            while(L<=R) {
                M = L + (R-L)/2;
                if((M<0 || a[M] == 1) &&  (M+1>n-1 || a[M+1]==0)) break;
                if( M<0 || a[M] == 1) L=M+1; else R=M-1;
            }
            //printf("i=%d, M=%d\n", i,M);
            v[i][0] = M+1;
            v[i][1] = i;
        }
        
        //for(int i = 0; i<m;i++) printf("v[%d] = {%d, %d}\n", i, v[i][0], v[i][1]);
        //printf("After sorting:\n");
        
        sort(v.begin(), v.end(), [](auto&lhs, auto&rhs){
           return (lhs[0] == rhs[0])?lhs[1]<rhs[1]:lhs[0]<rhs[0];
        });
        
        //for(int i = 0; i<m;i++) printf("v[%d] = {%d, %d}\n", i, v[i][0], v[i][1]);
        
        
        vector<int> ans;
        for(int i = 0;i<k;i++) ans.push_back(v[i][1]);
        return ans;
    }
};