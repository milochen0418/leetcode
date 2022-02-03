class Solution {
    //https://leetcode.com/problems/4sum
public:
    //Test Case 
/*
[1,0,-1,0,-2,2]
0
[-5,5,4,-3,0,0,4,-2]
4
*/    
    struct vector_hasher {
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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        //unordered_set<vector<int>> s;
        unordered_set<vector<int>, vector_hasher> s;
        int n = nums.size();
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                for(int k=j+1;k<n-1;k++) {
                    for(int l=k+1;l<n;l++) {
                        if(nums[i]+nums[j]+nums[k]+nums[l] == target) {
                            vector<int> v={nums[i],nums[j],nums[k],nums[l]};
                            if(s.find(v) == s.end()) {
                                s.insert(v);
                                result.push_back(v);
                            }
                        }
                    }
                }
            }
        }
        return result;
        //unordered_map<int, vector<pair<int,int>>> mp1;
        //unordered_map<int, vector<pair<int,int>>> mp2;
    }
};