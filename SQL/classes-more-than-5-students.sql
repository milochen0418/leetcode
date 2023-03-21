/*
# Write your MySQL query statement below
# https://leetcode.com/problems/classes-more-than-5-students
*/
select class from Courses group by class having count(student)>=5