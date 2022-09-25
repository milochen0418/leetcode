class Solution {
    //https://leetcode.com/problems/sort-the-people/
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<heights.size();i++) {
            mp[heights[i]] = i;
        }
        sort(heights.begin(), heights.end());
        reverse(heights.begin(), heights.end());
        for(auto &h:heights) ans.push_back(names[mp[h]]);
        return ans;

    }
};