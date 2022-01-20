class Solution {
    //https://leetcode.com/problems/meeting-rooms-ii
public:
    struct compare  {  
        bool operator()(const int& l, const int& r)  {  
            return l > r;   
        }  
    };  
        
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //default priority_queue is max queue. So following make min queue
        priority_queue<int,vector<int>, compare > start_q;  
        priority_queue<int,vector<int>, compare > end_q;  
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