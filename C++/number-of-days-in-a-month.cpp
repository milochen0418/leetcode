class Solution {
    //https://leetcode.com/problems/number-of-days-in-a-month
public:
    int numberOfDays(int year, int month) {
        //data reference here.
        //refer https://leetcode.com/problems/number-of-days-in-a-month 
        //refer https://m.law.iask.sina.com.cn/jx/sh/dhw3vEwSwe34.html  Feb in 1900 & 1800 only have 28 days
        unordered_set<int> big_months ={1,3,5,7,8,10,12};
        if(month==2){
            if(year%100==0) {
                if(year%400==0) 
                    return 29;
                else 
                    return 28;
            } else {
                if(year%4==0) 
                    return 29;
                else
                    return 28;
            }
        } else {
            if(big_months.find(month) != big_months.end())
                return 31;
            else
                return 30;
        }
        
    }
};