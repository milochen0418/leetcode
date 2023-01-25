/*
# https://leetcode.com/problems/find-followers-count/
# Write your MySQL query statement below
*/
select user_id, count(follower_id) as followers_count 
from Followers group by 1 order by user_id asc;