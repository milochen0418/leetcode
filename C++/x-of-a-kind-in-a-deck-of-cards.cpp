class Solution {
    //https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        //Because Time complexity for GCD(a,b) is O(log^2(min(a,b)) )
        //So the time complexity here is O(Nlog^2(N))
        //space compelxity is O(N)
        unordered_map<int,int> cnt;
        for(auto &i:deck) cnt[i]++;
        int common = 0;
        for(auto &[k,v]:cnt) common = gcd(common,v);
        if(common == 1) return false;
        return true;      
    }
};