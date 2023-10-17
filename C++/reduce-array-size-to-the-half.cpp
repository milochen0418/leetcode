class Solution {
    //https://leetcode.com/problems/reduce-array-size-to-the-half
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(auto &i: arr) mp[i]++;
        vector<int> v;
        for(auto &[key,val]:mp) v.push_back(val);
        sort(v.begin(), v.end());
        int ans = 0;
        int sum = 0;
        while(sum < n/2) {
            sum+=v.back();
            v.pop_back();
            ans++;
        }
        return ans;
    }
};