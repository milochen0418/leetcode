class Solution {
    //https://leetcode.com/problems/distribute-candies-among-children-i
    //article https://leetcode.com/problems/distribute-candies-among-children-i/discuss/4279629/C%2B%2B-or-simple-6-lines-Space-O(1)-Time-O(M3)
public:
    int distributeCandies(int n, int limit) {
        int ans = 0,m = min(n,limit);
        for(int i = 0; i<=m;i++) 
            for(int j = 0; j<=m;j++) 
                for(int k = 0; k<=m;k++) 
                    if(n == i+j+k ) ans++;
        return ans;
    }
};