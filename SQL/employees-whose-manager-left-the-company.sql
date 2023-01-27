/*
# https://leetcode.com/problems/employees-whose-manager-left-the-company
# Write your MySQL query statement below
# select employee_id from Employees where manager_id NOT IN (select employee_id from Employees)
*/
select employee_id from Employees where manager_id NOT IN (select employee_id from Employees) and salary<30000 order by employee_id asc;