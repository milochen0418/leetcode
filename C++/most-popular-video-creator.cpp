class Solution {
    //https://leetcode.com/problems/most-popular-video-creator
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        int n = creators.size();
        long long highest_popularity=0; 
        unordered_map <string,long long> popularity_mp;
        unordered_map <string,int> max_viewcount_mp; //creator, count of one view with max 
        unordered_map <string, vector<int>> idx_mp;//creator to idx vector. use idx can get id and view from ids and views
        
        
        for(int i = 0; i< n;i++) {
            string &creator = creators[i];
            popularity_mp[creator] += (long long)views[i];
            max_viewcount_mp[creator] = max(max_viewcount_mp[creator], views[i]);
            idx_mp[creator].push_back(i);
            highest_popularity = max(highest_popularity, popularity_mp[creator]);
        }
        
        for(auto& [creator, idxs]: idx_mp) {
            if(popularity_mp[creator] != highest_popularity) continue;
            string id = "zzzzzzz";
            for(auto &idx: idxs) {
                if(max_viewcount_mp[creator] != views[idx]) continue;
                if(ids[idx]<id) id = ids[idx];
            }
            ans.push_back({creator, id});
        }
        
        
        return ans;
    }
};