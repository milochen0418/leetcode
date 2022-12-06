class Solution {
    //https://leetcode.com/problems/divide-a-string-into-groups-of-size-k
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans = vector<string>(s.length()/k, string());
        if(s.length()%k != 0) ans.push_back(string());
        int i = 0;
        for(auto &c:s) ans[i++/k].push_back(c);
        while(ans.back().size() < k) ans.back().push_back(fill);
        return ans;      
    }
};