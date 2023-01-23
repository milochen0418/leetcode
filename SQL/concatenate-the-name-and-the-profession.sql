/*
# https://leetcode.com/problems/concatenate-the-name-and-the-profession
# Write your MySQL query statement below
*/
select person_id, concat(name,'(',substr(profession,1,1),')') as name from Person order by person_id desc