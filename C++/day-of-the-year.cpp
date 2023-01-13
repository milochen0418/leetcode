class Solution {
    //https://leetcode.com/problems/day-of-the-year
public:
    int dayOfYear(string date) {
        string date1 = date;
        date1[5]='0';
        date1[6]='1';
        date1[8]='0';
        date1[9]='1';
        return daysBetweenDates(date1,date)+1;
    }
    int daysBetweenDates(string date1, string date2) {
        vector<int> v1 = get_ymd(date1);
        vector<int> v2 = get_ymd(date2);
        int d1 = get_days(v1);
        int d2 = get_days(v2);
        return abs(d1-d2);
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
    
    vector<int> get_ymd(string date) {
        int year=0, mon=0,day=0;
        for(int i = 0;i<4;i++) 
            year=year*10+(date[i]-'0');
        for(int i = 5;i<7;i++) 
            mon=mon*10+(date[i]-'0');
        for(int i = 8;i<10;i++) 
            day=day*10+(date[i]-'0');
        return {year,mon,day};
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