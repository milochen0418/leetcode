/*
https://leetcode.com/problems/the-number-of-rich-customers/
# Write your MySQL query statement below
# select customer_id as rich_count from Store where amount>500;
# select distinct customer_id as rich_count from Store where amount>500;
*/
select count(distinct customer_id) as rich_count from Store where amount>500;