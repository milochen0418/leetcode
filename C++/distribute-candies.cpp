class Solution {
    //https://leetcode.com/problems/distribute-candies/
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;        
        for(auto &t:candyType) set.insert(t);        
        return min(candyType.size()/2, set.size());        
    }
};