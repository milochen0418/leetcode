class Solution {
    //https://leetcode.com/problems/maximum-number-of-coins-you-can-get
public:
    int maxCoins(vector<int>& piles) {
        //[2,4,1,2,7,8]
        //[8,7,4,2,2,1]
        //[9,8,7,6,5,1,2,3,4]
        //[9,8,7,6,5,4,3,2,1]
        sort(piles.begin(), piles.end(),[&](auto &lhs, auto&rhs){return lhs>rhs;});
        int n = piles.size(),m=n/3, ans=0;
        for(int i =0;i<m;i++) ans+=piles[i*2+1];  
        return ans;
        
    }
};