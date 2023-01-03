class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX,m=strs.size();
        string ans;
        for(auto &s:strs) n = min((int)s.length(), n);
        for(int j=0;j<n;j++) {
            for(int i=1; i<m; i++) 
                if(strs[i][j] != strs[0][j]) return ans;
            ans.push_back(strs[0][j]);
        }
        return ans;
    }
};