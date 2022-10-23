class Solution {
    //https://leetcode.com/problems/determine-if-two-events-have-conflict/
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = getTimeVal(event1[0]);
        int end1 = getTimeVal(event1[1]);
        int start2 = getTimeVal(event2[0]);
        int end2 = getTimeVal(event2[1]);
        
        if(end2>=start1 && end2<=end1) return true;
        if(end1>=start2 && end1<=end2) return true;
        if(start1 <= start2 && end1 >= end2) return true;
        if(start2 <= start1 && end2 >= end1) return true;
        return false;
        
    }
    int getTimeVal(string &s) {
        int hour = (s[0]-'0')*10+(s[1]-'0');
        int minute = (s[3]-'0')*10+(s[4]-'0');
        int totalMinute = minute + 60*hour;
        return totalMinute;
    }
};