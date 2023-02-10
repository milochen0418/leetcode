/*
# https://leetcode.com/problems/students-with-invalid-departments/
# Write your MySQL query statement below
*/

select s.id as id, s.name as name from Students s
where s.department_id not in (select id from Departments)
