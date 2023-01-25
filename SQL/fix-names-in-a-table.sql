/*
# https://leetcode.com/problems/fix-names-in-a-table
# Write your MySQL query statement below
*/
select user_id as user_id, 
concat(
        upper(substr(name,1,1)), 
        substr(lower(name),2,length(name)-1) 
      ) as name
from Users order by user_id asc;