class Solution {
    //https://leetcode.com/problems/burst-balloons
public:
    //Hash key method for unordered_map
    //https://jimmy-shen.medium.com/stl-map-unordered-map-with-a-vector-for-the-key-f30e5f670bae
    //https://stackoverflow.com/questions/10405030/c-unordered-map-fail-when-used-with-a-vector-as-key
    //Dynamic Programming refer
    //https://leetcode.com/explore/featured/card/dynamic-programming/630/an-introduction-to-dynamic-programming/4035/
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            //int hash = V.size();
            long hash = V.size();
            for(auto &i : V) {
                hash ^= (i + 0x9e3779b9 + (hash << 6) + (hash >> 2)) % INT_MAX;
                //hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };    
    unordered_map<vector<int>,int,VectorHasher> mp;
     
    int maxCoins(vector<int>& nums) {
        //return INT_MAX;
        if(mp.find(nums) != mp.end()) {
            return mp[nums];
        }
        if(nums.size() == 1) {
            mp.insert({nums, nums[0]});            
            return mp[nums];
        }
        
        int max_score = 0;
        for(int i=0; i < nums.size(); i++) {
            vector subnums = nums;
            int score = ((i-1<0)?1:nums[i-1]) * (nums[i]) * ((i+1>=nums.size())?1:nums[i+1]);
            subnums.erase(subnums.begin() + i);
            int candidate_score = score + maxCoins(subnums);
            if(candidate_score > max_score) {
                max_score = candidate_score;
            }
        }
        mp.insert({nums, max_score});
        return mp[nums];
    }
};