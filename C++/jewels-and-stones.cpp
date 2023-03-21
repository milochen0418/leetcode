class Solution {
    //https://leetcode.com/problems/jewels-and-stones
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> J = vector<int>(256,0);
        int ans = 0;
        for(auto &c:jewels) J[c]=1;
        for(auto &c:stones) ans+=J[c];
        return ans;
    }
};