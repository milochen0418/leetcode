/*
# Write your MySQL query statement below
In the SQL time-stamp, 1 million is mean one day 
*/
select distinct a.user_id from Confirmations a, Confirmations b
where a.user_id = b.user_id 
and b.time_stamp - a.time_stamp <= 1000000 
and b.time_stamp > a.time_stamp 


