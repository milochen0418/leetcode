class Solution {
    //https://leetcode.com/problems/count-days-spent-together
public:
    const vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> alice = get_day_interval(arriveAlice, leaveAlice);
        vector<int> bob = get_day_interval(arriveBob, leaveBob);
        if(alice[1] < bob[0]) return 0;
        if(bob[1] < alice[0]) return 0;
        return min(alice[1],bob[1]) - max(alice[0],bob[0]) + 1;        
    }
    vector<int> get_day_interval(string arrive, string leave) {
        vector<int> v;
        v.push_back(get_day(arrive));
        v.push_back(get_day(leave));
        return v;
    }
    int get_day(string date) {
        int m = date[1]-'0' + 10*(date[0]-'0');
        int d = date[4]-'0' + 10*(date[3]-'0');
        int day = 0;
        for(int i =0;i<m-1;i++) {
            day+=md[i];
        }
        day += d;
        return day;
    }
};