class Solution {
    //https://leetcode.com/problems/rings-and-rods
public:
    int countPoints(string rings) {
        vector<unordered_set<char>> vs = vector<unordered_set<char>>(10,unordered_set<char>());
        int n = rings.length()/2, ans = 0;
        for(int i = 0;i<n;i++) {
            char ring_color = rings[i*2];
            int rob_label = rings[i*2+1]-'0';
            vs[rob_label].insert(ring_color);
        }
        for(auto &s:vs) ans+=(s.size()==3);
        return ans;
    }
};