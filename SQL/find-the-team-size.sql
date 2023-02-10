/*
# https://leetcode.com/problems/find-the-team-size/
# Write your MySQL query statement below

Show team_id, team_size table by following SQL
select e.team_id as team_id, count(e.employee_id) as team_size 
from Employee e group by team_id)

*/

select e1.employee_id as employee_id, e2.team_size as team_size 
from Employee e1, ( 
    select e.team_id as team_id, count(e.employee_id) as team_size 
    from Employee e group by team_id) e2 
where e1.team_id = e2.team_id