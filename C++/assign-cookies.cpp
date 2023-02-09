class Solution {
    //https://leetcode.com/problems/assign-cookies/
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, n = s.size(), m = g.size(), i=0,j=0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        while(i<m && j<n) {
            if(s[j]>=g[i]) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};