/*
# https://leetcode.com/problems/sort-the-olympic-table
# Write your MySQL query statement below
sorting order by priority gold_medals desc > silver_medals desc > bronze_medals desc > country asc
*/
select * from Olympic order by gold_medals desc,silver_medals desc, bronze_medals desc, country asc;