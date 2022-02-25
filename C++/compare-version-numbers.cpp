class Solution {
    //https://leetcode.com/problems/compare-version-numbers
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1; getv(version1,v1);
        vector<int> v2; getv(version2,v2);
        int n = max(v1.size(), v2.size());
        for(int i=0; i<n; i++ ) {
            int val1 = i>=v1.size()?0:v1[i];
            int val2 = i>=v2.size()?0:v2[i];
            if(val1<val2) return -1;
            if(val1>val2) return 1;
        }
        return 0;
    }
    //getv:= Input 0.012.001 -> Output for v is {0, 12, 1}
    void getv(string s, vector<int>& v) {
        int n = s.length();
        int val = 0;
        for(int i=0; i<n; i++) {
            if(s[i] != '.') {
                val = val * 10 + (s[i]-'0');
            } else {
                v.push_back(val);
                val = 0;
            }
        }
        v.push_back(val);
    }
};