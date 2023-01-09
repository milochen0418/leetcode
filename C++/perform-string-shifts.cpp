class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shift_val = 1, n = s.length();
        for(auto &v: shift) {
            shift_val += (v[0]*2-1)*v[1];
            shift_val = (shift_val+n)%n;
        }
        string ans = string(n,' ');
        for(int i = 0;i<n;i++) {
            ans[i] = s[(i+shift_val)%n];
        }
        return ans;
    }
};
/* 
Pass
"abcdefg"
[[1,1],[1,1],[0,2],[1,3]]
"abc"
[[0,1],[1,2]]

Fail
"mecsk"
[[1,4],[0,5],[0,4],[1,1],[1,5]]
*/