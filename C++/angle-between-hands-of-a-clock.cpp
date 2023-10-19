class Solution {
    //https://leetcode.com/problems/angle-between-hands-of-a-clock
public:
    double angleClock(int hour, int minutes) {
        double m = ((double)minutes)/60.0f;
        double h = (hour%12)/12.0f;
        h += m*(1.0f/12.0f);
        double d = abs(m-h)*360.0f ;
        return min(d, 360-d);
    }
};