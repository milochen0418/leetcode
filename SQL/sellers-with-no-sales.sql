/*
# https://leetcode.com/problems/sellers-with-no-sales/
# Write your MySQL query statement below
*/
select ser.seller_name from Seller ser where ser.seller_id NOT IN 
(select distinct seller_id from Orders where year(sale_date) = 2020)
order by ser.seller_name asc;