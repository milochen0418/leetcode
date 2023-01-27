/*
# https://leetcode.com/problems/employees-with-missing-information
# Write your MySQL query statement below
# select * from Employees e join Salaries s on e.employee_id=s.employee_id;
# select e.employee_id from Employees e join Salaries s on e.employee_id=s.employee_id;

For this input data
{"headers":{"Employees":["employee_id","name"],"Salaries":["employee_id","salary"]},"rows":{"Employees":[[2,"Crew"],[4,"Haven"],[5,"Kristian"]],"Salaries":[[5,76071],[1,22517],[4,63539]]}}
Employees have 2,4,5
Salaries  have 5,1,4
This "SELECT employee_id FROM Employees UNION SELECT employee_id FROM Salaries" will get all ids
*/

select * from (SELECT employee_id FROM Employees UNION SELECT employee_id FROM Salaries) tbl
WHERE
    (
    employee_id not in (SELECT employee_id FROM Employees) 
    AND 
    employee_id in (SELECT employee_id FROM Salaries)
    )
OR
    (
    employee_id in (SELECT employee_id FROM Employees) 
    AND
    employee_id not in (SELECT employee_id FROM Salaries) 
    )
order by tbl.employee_id asc