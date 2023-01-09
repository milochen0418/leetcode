class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shift_val = 0, n = s.length();
        for(auto &v: shift) {
            shift_val += (v[0]*2-1)*v[1];
            shift_val = (shift_val+n)%n;
        }
        //printf("shift %d.\n",shift_val);
        string ans = string(n,' ');
        for(int i = 0;i<n;i++) {
            ans[i] = s[(i+(n-shift_val))%n];
        }
        return ans;
    }
};