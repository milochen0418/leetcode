class Solution {
    //https://leetcode.com/problems/number-of-valid-clock-times
public:
    int countTime(string time) {
        vector<int> v(5,1);
        if(time[0]=='?' && time[1]=='?') {
            v[1] = 24;
        } else if(time[0]=='?') {
            if(time[1]<='3') 
                v[0]=3;//0,1,2
            else
                v[0]=2;//0,1
        } else if(time[1]=='?') {
            if(time[0]<='1') {
                v[1] = 10;
            } else { //2
                v[1] = 4;//0123
            }
        }
        if(time[3]=='?') v[3]=6;
        if(time[4]=='?') v[4]=10;
        return v[0]*v[1]*v[2]*v[3]*v[4];
    }
};