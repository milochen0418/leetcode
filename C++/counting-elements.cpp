class Solution {
    //https://leetcode.com/problems/counting-elements
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> s;
        for(auto &i:arr) s.insert(i);
        int ans = 0;
        for(auto &i:arr) if(s.find(i+1)!=s.end()) ans++;
        return ans;
    }
};