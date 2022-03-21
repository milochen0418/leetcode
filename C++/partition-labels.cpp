class Solution {
    //https://leetcode.com/problems/partition-labels/
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> begin_mp; 
        unordered_map<char,int> end_mp;
        unordered_set<char> hset; //[begin,end] for c in hset
        vector<char> v;
        s.push_back('-');//dummy 
        int n = s.length();
        
        //Figure out all interval of letter
        //and letter in v is increasing order of index in s
        for(int i = 0; i < n; i++) {
            if(hset.find(s[i]) == hset.end()) {
                hset.insert(s[i]);
                v.push_back(s[i]);
            }
            if (begin_mp[s[i]] == 0 && i!=0) {
                begin_mp[s[i]] = i;
            }
            end_mp[s[i]] = i;
        }
        begin_mp[s[0]] = 0;
        
        int m = v.size();
        int begin =-1, end=-1;
        for(int i = 0; i<m;i++) {
            if(begin_mp[v[i]] > end ) {
                if(begin >= 0) ans.push_back(end-begin+1);
                begin = begin_mp[v[i]];
                end = end_mp[v[i]];
            } else {
                end = max(end, end_mp[v[i]]);
            }
        }
        return ans;      
    }
};