/*
# https://leetcode.com/problems/customers-who-never-order
# Write your MySQL query statement below
# Use where ... not in with (select ....)
*/
select name as Customers 
from Customers where id not in (select customerId from Orders);