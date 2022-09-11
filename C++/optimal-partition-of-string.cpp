class Solution {
    //https://leetcode.com/problems/optimal-partition-of-string/
public:
    int partitionString(string s) {
        int ans = 0, n = s.length();
        for(int i = 0; i < n;ans++) {
            unordered_set<char> set;
            while(i<n) {
                if(set.find(s[i]) != set.end()) break;                
                set.insert(s[i]);
                i++;
            }
        }
        return ans;   
    }
};