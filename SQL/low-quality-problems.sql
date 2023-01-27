/*
# https://leetcode.com/problems/low-quality-problems
# Write your MySQL query statement below
*/
select problem_id from Problems where (100*likes)/(likes+dislikes) < 60 order by problem_id asc;