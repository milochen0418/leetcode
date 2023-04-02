class Solution {
    //https://leetcode.com/problems/mice-and-cheese/
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<vector<int>>v;
        int n = reward1.size();
        for(int i = 0;i<n;i++) {
            vector<int> q = {reward1[i], reward2[i], reward1[i]-reward2[i]};
            v.push_back(q);
        }
        sort(v.begin(), v.end(), [&](auto &lhs, auto &rhs) {
            return lhs[2]>rhs[2];
        });
        int ans = 0;
        for(int i= 0;i<n;i++) ans+=v[i][i>=k];

        return ans;
    }
};