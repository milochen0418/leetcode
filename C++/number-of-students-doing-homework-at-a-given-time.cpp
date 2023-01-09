class Solution {
    //https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans=0, n = startTime.size();
        for(int i = 0; i<n;i++) if(startTime[i]<=queryTime && queryTime<=endTime[i]) ans++;
        return ans;
    }
};