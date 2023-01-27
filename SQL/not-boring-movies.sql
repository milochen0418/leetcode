/*
# https://leetcode.com/problems/not-boring-movies
# Write your MySQL query statement below
*/
select * from Cinema where description<>"boring" and id mod 2 = 1 order by rating desc; 