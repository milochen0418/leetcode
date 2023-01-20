class Solution {
    //https://leetcode.com/problems/minimum-index-sum-of-two-lists
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        int minidxsum = INT_MAX;
        for(int i = 0;i<list1.size();i++) { 
            string &s = list1[i];
            for(int j = 0;j<list2.size();j++) {
                if(s == list2[j]) {
                    if(mp.find(s) == mp.end())mp[s]=INT_MAX; 
                    mp[s]=min(mp[s], i+j);
                    minidxsum = min(minidxsum, i+j);
                }
            }
        }
                    
        vector<string> ans;
        for(auto &[k,v]:mp) 
            if(v==minidxsum) 
                ans.push_back(k);
        return ans;
    }
};