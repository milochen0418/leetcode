class Solution {
    //https://leetcode.com/problems/maximum-number-of-balloons
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp = vector<int>(256,0);
        for(auto &c:text) mp[c]++;
        //balloon: b1,a1,n1,l2,o2, 
        int min1 = min(min(mp['b'],mp['a']), mp['n']);
        int min2 = min(mp['l'], mp['o']);
        min2/=2;
        return min(min1,min2);
        
    }
};