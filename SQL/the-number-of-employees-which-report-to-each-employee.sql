/*
# https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee
# article https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/discuss/3105131/MySQL-solution-explanation
# Write your MySQL query statement below
Input 
{"headers":{"Employees":["employee_id","name","reports_to","age"]},"rows":{"Employees":[[9,"Hercy",null,43],[6,"Alice",9,41],[4,"Bob",9,36],[2,"Winston",null,37]]}}

select count(employee_id), name, reports_to from Employees group by 3 
Output
{"headers": ["count(employee_id)", "name", "reports_to"], "values": [
[2, "Hercy", null], 
[2, "Alice", 9]]}

select count(employee_id), name, reports_to from Employees where reports_to is not null group by 3 
Output
{"headers": ["count(employee_id)", "name", "reports_to"], "values": [
[2, "Alice", 9]]}

select reports_to as employee_id, count(employee_id) as reports_count from Employees where reports_to is not null group by 1 
Output
{"headers": ["employee_id", "reports_count"], "values": [[9, 2]]}

select t.employee_id as employee_id, t.reports_count as reports_count
from (select reports_to as employee_id, count(employee_id) as reports_count from Employees where reports_to is not null group by 1) t
Output
{"headers": ["employee_id", "reports_count"], "values": [[9, 2]]}


select t.employee_id as employee_id, t.reports_count as reports_count
from (
    select reports_to as employee_id, count(employee_id) as reports_count 
    from Employees where reports_to is not null group by 1) t 
left join Employees e on t.employee_id = e.employee_id 
Output
{"headers": ["employee_id", "reports_count"], "values": [[9, 2]]}


select t.employee_id as employee_id, e.name as name, t.reports_count as reports_count
from (
    select reports_to as employee_id, count(employee_id) as reports_count 
    from Employees where reports_to is not null group by 1) t 
left join Employees e on t.employee_id = e.employee_id 
Output
{"headers": ["employee_id", "name", "reports_count"], "values": [[9, "Hercy", 2]]}

idea. Get average of all reporter who is employee to the same employee
select 
    t.employee_id as employee_id, 
    e.name as name, 
    t.reports_count as reports_count,
    t.average_age as average_age
from (
    select reports_to as employee_id, 
    count(employee_id) as reports_count, 
    avg(age) as average_age
    from Employees where reports_to is not null group by 1) t 
left join Employees e on t.employee_id = e.employee_id 
Output
{"headers": ["employee_id", "name", "reports_count", "average_age"], "values": [[9, "Hercy", 2, 38.5000]]}


idea. Use round(xx,0) to get integer only but rounding. call 四捨五入 in Chinese.

select 
    t.employee_id as employee_id, 
    e.name as name, 
    t.reports_count as reports_count,
    t.average_age as average_age
from (
    select 
        reports_to as employee_id, 
        count(employee_id) as reports_count, 
        round(avg(age),0) as average_age
    from Employees where reports_to is not null group by 1
    ) t 
left join Employees e on t.employee_id = e.employee_id 
Output
{"headers": ["employee_id", "name", "reports_count", "average_age"], "values": [[9, "Hercy", 2, 39]]}

*/

select 
    t.employee_id as employee_id, 
    e.name as name, 
    t.reports_count as reports_count,
    t.average_age as average_age
from (
    select 
        reports_to as employee_id, 
        count(employee_id) as reports_count, 
        round(avg(age),0) as average_age
    from Employees where reports_to is not null group by 1
    ) t 
left join Employees e on t.employee_id = e.employee_id 
order by employee_id asc

