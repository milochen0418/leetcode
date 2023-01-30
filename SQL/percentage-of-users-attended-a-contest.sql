/*
# https://leetcode.com/problems/percentage-of-users-attended-a-contest/
# Write your MySQL query statement below
We can get number of user in Users table and save it into the variable @total
select count(user_id) into @total from Users
But we cannot use variable
# select count(user_id) into @total from Users;
# select contest_id, round( (100*count(user_id))/@total, 2) as percentage from Register group by contest_id;

Thus we can have the following accepted solution

select contest_id, 
    round ((100*count(user_id))/(select count(user_id) from Users),2) as percentage 
from Register group by contest_id 
order by percentage desc, contest_id asc;

But Our purpose is to saveing query result of  (select count(user_id) from Users),2)
For this purpose , we can use WITH 
(refer WITH in this article: https://zhuanlan.zhihu.com/p/397195826) 

with var as (...)  select ... from Table, var ... 
*/


with var as
(
    select count(*) as total from Users
)
select contest_id, 
    round ((100*count(user_id))/var.total,2) as percentage 
from Register, var group by contest_id 
order by percentage desc, contest_id asc;
