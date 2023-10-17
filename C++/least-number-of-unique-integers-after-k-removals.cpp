class Solution {
    //https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &i:arr) mp[i]++;
        vector<int> vec;
        for(auto &[k,v]: mp ) 
            vec.push_back(v);
        sort(vec.begin() ,vec.end());
        int n = vec.size();
        int i = 0;
        for(i = 0; i < n;i++) {
            if(vec[i]>k) break;
            k-=vec[i];
        }
        return vec.size()-i;;
    }
};