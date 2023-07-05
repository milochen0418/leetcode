class Solution {
    //https://leetcode.com/problems/row-with-maximum-ones
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans_idx = -1, max_cnt_one = -1; 
        for(int i = 0; i<m; i++) {
            int cnt_one = 0;
            for(auto &v: mat[i]) cnt_one+=(v==1);
            if(cnt_one>max_cnt_one) {
                ans_idx = i;
                max_cnt_one = cnt_one;
            }
        }
        return {ans_idx, max_cnt_one};
    }
};