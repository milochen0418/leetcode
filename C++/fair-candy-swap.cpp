class Solution {
    //https://leetcode.com/problems/fair-candy-swap
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0, sumBob = 0;
        for(auto &i: aliceSizes) sumAlice+=i;
        for(auto &i: bobSizes) sumBob+=i;
        int diff = (sumBob - sumAlice)/2;
        unordered_set<int> aliceSet, bobSet;
        for(auto &i: aliceSizes) aliceSet.insert(i);
        for(auto &i: bobSizes) bobSet.insert(i);
        for(auto &i: aliceSet) 
            if(bobSet.find(i+diff) != bobSet.end()) 
                return {i,i+diff};
        return {1,1};
    }
};