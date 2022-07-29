class Solution {
    //https://leetcode.com/problems/top-k-frequent-words
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string ,int>mp;
        for(auto &s: words) mp[s]++;
        vector<string> a;
        for(auto &[key,val]:mp) a.push_back(key);
        sort(a.begin(), a.end(), [&](auto& lhs, auto& rhs) {
            if(mp[lhs] == mp[rhs]) {
                /* 
                //lexicographical order 0,01,02,1,10,11 ... 
                int ln = lhs.length(), rn = rhs.length(), i=0;
                while(i<ln && i<rn ){
                    if(lhs[i]==rhs[i]) {
                        i++; 
                    } else {
                        return lhs[i]<rhs[i];
                    }
                }
                return ln<rn;
                */
                return lhs<rhs;
            } else {
                return mp[lhs]>mp[rhs];
            }
        });
        for(int i = 0; i<k;i++) ans.push_back(a[i]);
        return ans;
    }
};