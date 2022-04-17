class Solution {
    //https://leetcode.com/problems/top-k-frequent-elements
public:

/*
尾玉分享

auto f = [](int n) {
     if (f == 0) return 0;
     return 1+ f(n-1);
};

functional<int(int)> f = [](int n) -> int {
     if (f == 0) return 0;
     return 1+ f(n-1);
};

*/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //return answer1(nums, k);
        /*
        unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        vector<int> ans;
        for(auto &i:nums) mp[i]++;
        for(auto& [key,val]:mp) v.push_back({key,val});
        sort(v.begin(), v.end(), [](auto&lhs, auto&rhs) { 
            return lhs.second > rhs.second;
        });
        for(int i=0;i<k;i++) ans.push_back(v[i].first);
        return ans;
        */
        vector<int> ans;
        unordered_map<int,int> mp;

        unordered_map<int,int> &mp;
        auto compare = [](pair<int,int> lhs, pair<int,int> rhs) {
            return lhs.second >rhs.second;
        };
        
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>,
            decltype(compare)
        >minQ(compare);


        //unordered_map<int,int> mp;
        for(auto &i:nums) mp[i]++;
        for(auto& [key,val]:mp) {
            minQ.push({key,val});
            if(minQ.size()>k)minQ.pop();
        }
        while(!minQ.empty()){
            ans.push_back(minQ.top().first);
            minQ.pop();
        }    
        return ans;
        
    }
    
    vector<int> answer1(vector<int>& nums, int k) {
                unordered_map<int,int> mp;
        vector<pair<int,int>> v;
        vector<int> ans;
        for(auto &i:nums) mp[i]++;
        for(auto& [key,val]:mp) v.push_back({key,val});
        sort(v.begin(), v.end(), [](auto&lhs, auto&rhs) { 
            return lhs.second > rhs.second;
        });
        for(int i=0;i<k;i++) ans.push_back(v[i].first);
        return ans;
    }
};