class Solution {
    //https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> cnt;
        for(auto &i:deck) cnt[i]++;
        int common = 0;
        for(auto &[k,v]:cnt) common = gcd(common,v);
        if(common == 1) return false;
        return true;      
    }
};