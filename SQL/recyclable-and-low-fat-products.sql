/*
# https://leetcode.com/problems/recyclable-and-low-fat-products
# Write your MySQL query statement below
*/
select product_id from Products where low_fats='Y' and recyclable='Y'