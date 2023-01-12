class Solution {
    //https://leetcode.com/problems/day-of-the-week
    //article https://leetcode.com/problems/day-of-the-week/discuss/3039876/C%2B%2B-or-Calculate-from-1900-01-01-Monday
public:
    vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string dayOfTheWeek(int day, int month, int year) {
        int monday_base = get_days({1900,01,01});
        int check_day = get_days({year, month ,day});
        return weekdays[(check_day-monday_base+1)%7];
        //1900-01-01 is Monday
    }
    
    int get_days(vector<int> ymd) {
        int d = 0;
        for(int i = 0; i<ymd[0];i++) 
            d+=days_of_year(i);
        for(int i = 1; i<ymd[1];i++) 
            d+=days_of_month(ymd[0],i);
        d+=ymd[2];
        return d;
    }
    
    vector<int> days_in_months = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int days_of_month(int year, int month) {
        if(month==2 && year%4==0 && (year%400==0 || year%100!=0)) return 29;
        return days_in_months[month];
    }
    int days_of_year(int year) {
        int res = 0;
        for(int i = 1;i<=12;i++) res+=days_of_month(year,i);
        return res;
    }        
};