class Solution {
    //https://leetcode.com/problems/distribute-candies-among-children-i
    //article https://leetcode.com/problems/distribute-candies-among-children-i/discuss/4279629/C%2B%2B-or-simple-5-lines-O(M2)
public:
    int distributeCandies(int n, int limit) {
        int ans = 0,m = min(n,limit);
        for(int i = 0; i<=m;i++) 
            for(int j = 0; j<=m;j++) 
                if( n-(i+j)>=0 && n-(i+j)<=m) ans++;
        return ans;
    }
};