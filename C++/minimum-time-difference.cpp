class Solution {
    //https://leetcode.com/problems/minimum-time-difference
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), [&](auto&lhs, auto&rhs) {
            return getMinutes(lhs)<getMinutes(rhs);
        });
        
        if(timePoints.size()>1)timePoints.push_back(timePoints[0]);
        int ans = INT_MAX, n = timePoints.size();
        for(int i=1;i<n;i++) {
            int prev = getMinutes(timePoints[i-1]);
            int curr = getMinutes(timePoints[i]);
            ans = min(ans, min(abs(curr-prev), abs(curr-prev+60*24)));
        }
        return ans;
    }
    int getMinutes(string &str)  {
        int hour = (str[0]-'0')*10 + str[1]-'0';
        int min = (str[3]-'0')*10 + str[4]-'0';
        return hour*60 + min;
    } 
};