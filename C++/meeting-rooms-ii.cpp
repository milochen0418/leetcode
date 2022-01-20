class Solution {
    //https://leetcode.com/problems/meeting-rooms-ii
    //Time complexity of priority queue https://iq.opengenus.org/priority-queue-cpp-stl/
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>, greater<int> > start_q;  
        priority_queue<int,vector<int>, greater<int> > end_q;  
        for(auto v:intervals) {
            start_q.push(v[0]);
            end_q.push(v[1]);
        }
        int maximum = 0; 
        int cnt = 0; 
        while(!(start_q.empty() && end_q.empty())) {
            int start_val = start_q.empty() ? INT_MAX: start_q.top();
            int end_val = end_q.empty() ? INT_MAX: end_q.top();
            if(start_val <= end_val) {
                start_q.pop();
                cnt = cnt + 1;
            } 
            if(start_val >= end_val) {
                end_q.pop();
                cnt = cnt - 1;
            } 
            maximum = max(maximum, cnt);
        }
        return maximum; 
    }
};