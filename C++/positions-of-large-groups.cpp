class Solution {
    //https://leetcode.com/problems/positions-of-large-groups
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        s.push_back('_');
        int L=0, R=0, n = s.length(), cnt=0;
        while(R<n) {
            if(s[L] == s[R]) {
                R++;
            } else {
                if(R-1-L>=2) ans.push_back({L,R-1});
                L=R;
            }
        }
        return ans;
    }
};