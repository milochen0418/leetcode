/* 
# https://leetcode.com/problems/customer-placing-the-largest-number-of-orders
# Write your MySQL query statement below    
# select customer_number, count(order_number) as cnt from Orders o group by 1 order by cnt desc limit 0,1
*/
select tmp.customer_number as customer_number from (
select customer_number, count(order_number) as cnt from Orders o group by 1 order by cnt desc limit 0,1
) tmp;