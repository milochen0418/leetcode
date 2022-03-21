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
        ans.push_back(s.length());
        int n = s.length();
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
        
        
        int m = v.size();
        int begin =-1, end=-1;//dummy for begin
        for(int i = 0; i<m;i++) {
            if(begin_mp[v[i]] > end ) {
                if(begin >= 0) ans.push_back(end-begin+1);
                begin = begin_mp[v[i]];
                end = end_mp[v[i]];
            } else {
                end = max(end, end_mp[v[i]]);
            }
            /*
            if(begin_mp[v[i]] <= i && i<= end_mp[v[i]]) {
                begin = min(begin,  begin_mp[v[i]]);
                end = max(end, end_mp[v[i]]);
            }*/
        }
        return ans;
            
        
    }
};