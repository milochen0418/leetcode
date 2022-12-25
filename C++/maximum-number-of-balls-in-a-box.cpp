class Solution {
    //https://leetcode.com/problems/maximum-number-of-balls-in-a-box
    //article https://leetcode.com/problems/maximum-number-of-balls-in-a-box/discuss/2950509/C%2B%2B-or-80-faster-or-time-O(NlogN)-space-O(LogN)
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> mp = vector<int>(9*5+1,0); //because maximum is 9^5
        int ans = 0;
        for(int i = lowLimit;i<=highLimit;i++) {
            int q=i, boxnum = 0;
            while(q>0) {
                boxnum+=q%10;
                q/=10;
            } 
            mp[boxnum]++;
        }
        for(auto &i:mp)ans = max(ans, i);
        return ans;
    }
};