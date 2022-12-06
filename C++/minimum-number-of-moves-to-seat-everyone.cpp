class Solution {
    //https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans=0, n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for(int i = 0;i<n;i++) ans+=abs(seats[i]-students[i]);
        return ans;
    }
};