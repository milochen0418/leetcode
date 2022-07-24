class Solution {
    //https://leetcode.com/problems/meeting-rooms
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto&lhs, auto&rhs){
           return lhs[0] < rhs[0];
        });
        for(int i =1;i<intervals.size();i++) {
            if(intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
};