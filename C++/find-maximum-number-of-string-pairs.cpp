class Solution {
    //https://leetcode.com/problems/find-maximum-number-of-string-pairs
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        vector<string> rwords; // reversed words
        for(auto &w: words) {
            string s = w;
            reverse(s.begin(), s.end());
            rwords.push_back(s);
        }
        int n = words.size();
        int ans = 0;
        for(int i = 0;i<n ;i++) {
            for(int j = i+1;j<n;j++) {
                if(rwords[i] == words[j]) ans++;
            }
        }
        return ans;
    }
};