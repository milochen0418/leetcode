/*
# https://leetcode.com/problems/biggest-single-number
# Write your MySQL query statement below
*/
select max(t.num) as num from (select num, count(num) as cnt from MyNumbers group by 1 having cnt=1) t;