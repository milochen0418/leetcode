/*
# https://leetcode.com/problems/product-sales-analysis-ii
# Write your MySQL query statement below
*/
select Sales.product_id as product_id, sum(Sales.quantity) as total_quantity from Sales group by 1; 