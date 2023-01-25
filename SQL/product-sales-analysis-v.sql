/*
# https://leetcode.com/problems/product-sales-analysis-v
# Write your MySQL query statement below
*/
select Sales.user_id as user_id, sum(Sales.quantity*Product.price) as spending 
from Sales left join Product on Sales.product_id = Product.product_id 
group by 1 order by spending desc;