class Solution {
    //https://leetcode.com/problems/most-popular-video-creator
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        int n = creators.size();
        long long highest_popularity=0; 
        unordered_map <string,long long> popularity_mp;
        unordered_map <string,int> max_viewcount_mp; //creator, count of one view with max 
        unordered_map <string, string> id_mp;
        
        for(int i = 0; i< n;i++) {
            string &creator = creators[i];
            popularity_mp[creator] += (long long)views[i];
            if(id_mp.find(creator) == id_mp.end()) {
                id_mp[creator] = ids[i];
                max_viewcount_mp[creator] = views[i];
            } else if(max_viewcount_mp[creator] < views[i]) {
                id_mp[creator] = ids[i];
                max_viewcount_mp[creator] = views[i];
            } else if(max_viewcount_mp[creator] == views[i]){
                if(id_mp[creator] > ids[i])  id_mp[creator] = ids[i];
            }
            highest_popularity = max(highest_popularity, popularity_mp[creator]);
        }
        for(auto& [creator,id]: id_mp) {
            if(popularity_mp[creator] != highest_popularity) continue;
            ans.push_back({creator, id_mp[creator]});
        }
        return ans;
                
    }
    
    vector<vector<string>> mostPopularCreatorVer01(vector<string>& creators, vector<string>& ids, vector<int>& views) {
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