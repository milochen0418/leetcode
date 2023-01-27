/*
# https://leetcode.com/problems/primary-department-for-each-employee
# Write your MySQL query statement below
Input {"headers":{"Employee":["employee_id","department_id","primary_flag"]},"rows":{"Employee":[
["1","1","N"],
["2","1","Y"],
["2","2","N"],
["3","3","N"],
["4","2","N"],
["4","3","Y"],
["4","4","N"]]}}

select employee_id, department_id from Employee 
group by 1 having count(employee_id)=1

{"headers": ["employee_id", "department_id"], "values": 
[[1, 1], 
 [3, 3]]}

select employee_id, department_id from Employee 
where primary_flag='Y'
{"headers": ["employee_id", "department_id"], "values": 
[[2, 1], 
 [4, 3]]}
 
*/

(
    select employee_id, department_id from Employee 
    group by 1 having count(employee_id)=1
)
UNION
(
    select employee_id, department_id from Employee 
    where primary_flag='Y'
)