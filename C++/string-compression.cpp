class Solution {
    //https://leetcode.com/problems/string-compression
public:
    int compress(vector<char>& chars) {
        chars.push_back('\t');
        int n = chars.size();
        int cnt = 1;
        string ans;
        for(int i = 0; i<n-1;i++) {
            if(chars[i] != chars[i+1]) {
                ans.push_back(chars[i]);
                if(cnt>1) ans.append(to_string(cnt));
                cnt = 1;
            } else {
                cnt++;
            }
        }        
        int ret = ans.length();
        for(int i = 0; i<ret;i++) chars[i] = ans[i];
        return ret;
    }
};