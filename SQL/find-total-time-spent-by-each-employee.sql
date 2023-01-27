/*
//https://leetcode.com/problems/find-total-time-spent-by-each-employee
# Write your MySQL query statement below
select emp_id,event_day,sum(out_time-in_time) as total_time 
from Employees group by 1,2

Input: 
{"headers":{"Employees":["emp_id","event_day","in_time","out_time"]},"rows":{"Employees":[["1","2020-11-28","4","32"],["1","2020-11-28","55","200"],["1","2020-12-3","1","42"],["2","2020-11-28","3","33"],["2","2020-12-9","47","74"]]}}

select emp_id,event_day,sum(out_time-in_time) as total_time 
from Employees group by 1,2

Output:
{"headers": ["emp_id", "event_day", "total_time"], "values": [
[1, "2020-11-28", 173], 
[1, "2020-12-03", 41], 
[2, "2020-11-28", 30],
[2, "2020-12-09", 27]]}
*/


select emp_id,event_day as day,sum(out_time-in_time) as total_time 
from Employees group by 1,2
