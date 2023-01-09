class Solution {
    //https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxv=0;
        for(auto &i:candies) maxv = max(maxv,i);
        for(auto &i:candies) ans.push_back(extraCandies+i>=maxv);
        return ans;
    }
};