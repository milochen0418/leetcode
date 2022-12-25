class Solution {
    //https://leetcode.com/problems/second-largest-digit-in-a-string
public:
    int secondHighest(string s) {
        unordered_set<int> ss;
        for(auto &c:s) {
            if('0'<=c && c<='9') ss.insert(c-'0');
        }
        if(ss.size()<=1) return -1;
        vector<int> v;
        for(auto &i:ss) v.push_back(i);
        sort(v.begin(), v.end(), greater<int>());
        return v[1];
    }
};