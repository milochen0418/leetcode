/*
# https://leetcode.com/problems/percentage-of-users-attended-a-contest/
# Write your MySQL query statement below
We can get number of user in Users table and save it into the variable @total
select count(user_id) into @total from Users
But we cannot use variable
# select count(user_id) into @total from Users;
# select contest_id, round( (100*count(user_id))/@total, 2) as percentage from Register group by contest_id;

Thus we can have the following solution
*/


select contest_id, 
    round ((100*count(user_id))/(select count(user_id) from Users),2) as percentage 
from Register group by contest_id 
order by percentage desc, contest_id asc;
