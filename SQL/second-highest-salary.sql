/*
# //https://leetcode.com/problems/second-highest-salary/
# Write your MySQL query statement below
LIMIT begin, len mean start from begin and get len number of element
When begin=0, it is the first element

# select salary as SecondHighestSalary from Employee order by salary desc LIMIT 1,1
# When the number of rows in table is smaller than 2, this SQL cannot be passed.

# select null as SecondHighestSalary;
# select count(*) from Employee

*/

select case when count(*)<=1 then null 
        else (select distinct salary from Employee order by salary  desc LIMIT 1,1)
        end as SecondHighestSalary from Employee;
