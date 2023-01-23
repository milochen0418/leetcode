/*
# https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher
# Write your MySQL query statement below
# group by 1 mean the group by according to first column of select
*/
select teacher_id, count(distinct subject_id) as cnt from Teacher group by 1;
