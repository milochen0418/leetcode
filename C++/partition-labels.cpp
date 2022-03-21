class Solution {
    //https://leetcode.com/problems/partition-labels/
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> begin_mp; 
        unordered_map<char,int> end_mp;
        unordered_set<char> hset; //[begin,end] for c in hset
        int n = s.length();
        for(int i = 0; i < n; i++) {
            hset.insert(s[i]);
            if (begin_mp[s[i]] == 0 && i!=0) {
                begin_mp[s[i]] = i;
            }
            end_mp[s[i]] = i;
        }
    }
};