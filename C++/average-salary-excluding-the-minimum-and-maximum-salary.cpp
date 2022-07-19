class Solution {
    //https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
public:
    double average(vector<int>& salary) {
        int max_salary = INT_MIN;
        int min_salary = INT_MAX;
        int sum = 0;
        for(auto &i:salary) {
            sum+=i;
            max_salary = max(max_salary, i);
            min_salary = min(min_salary, i);
        }
        
        sum-=(max_salary+min_salary);
        return (double)sum/(double)(salary.size()-2);
    }
};