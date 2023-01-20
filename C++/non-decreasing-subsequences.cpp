class Solution {
    //https://leetcode.com/problems/non-decreasing-subsequences/
public:
    struct vector_hasher {
        int operator()(const vector<int> &V) const {
            long hash = V.size();
            for(auto &i : V) {
                hash ^= (i + 0x9e3779b9 + (hash << 6) + (hash >> 2)) % INT_MAX;
            }
            return hash;
        }
    };    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<vector<int>, vector_hasher> s;
        s.insert(vector<int>());
        int n = nums.size();
        for(int i = 0; i<n;i++) {
            unordered_set<vector<int>, vector_hasher> append_set;
            for(auto &v:s) {
                if(v.size()==0 || nums[i] >=v.back() ) {
                    vector<int> newv = v;
                    newv.push_back(nums[i]);
                    append_set.insert(newv);
                }
            }
            for(auto &v:append_set) s.insert(v);
        }
        
        vector<vector<int>> ans;
        for(auto &v:s) if(v.size()>=2) ans.push_back(v);
        return ans;
    }
};
