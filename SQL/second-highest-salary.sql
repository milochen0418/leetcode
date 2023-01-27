/*
# //https://leetcode.com/problems/second-highest-salary/
# Write your MySQL query statement below
LIMIT begin, len mean start from begin and get len number of element
When begin=0, it is the first element

# select salary as SecondHighestSalary from Employee order by salary desc LIMIT 1,1
Wrong Answer
Input: {"headers":{"Employee":["id","salary"]},"rows":{"Employee":[[1,100]]}}
Output: {"headers": ["SecondHighestSalary"], "values": []}
Expected: {"headers": ["SecondHighestSalary"], "values": [[null]]}
# When the number of rows in table is smaller than 2, this SQL cannot be passed.
*/
