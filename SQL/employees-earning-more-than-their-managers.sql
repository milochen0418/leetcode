/*
# Write your MySQL query statement below
# https://leetcode.com/problems/employees-earning-more-than-their-managers
*/
SELECT a.name AS Employee FROM Employee a LEFT JOIN Employee b ON a.managerId=b.id WHERE a.salary > b.salary;