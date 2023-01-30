/*
# https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/
# Write your MySQL query statement below

Input 
As the Input of example 1

SQL
select 
    v.visit_id,
    v.customer_id as customer_id,
    count(v.customer_id) as count_no_trans
from Visits v where v.visit_id not in (
    select distinct visit_id from Transactions
) group by customer_id

Output
{"headers": ["visit_id", "customer_id", "count_no_trans"], "values": [[4, 30, 1], [6, 96, 1], [7, 54, 2]]}



Expected
{"headers": ["customer_id", "count_no_trans"], "values": [[54, 2], [30, 1], [96, 1]]}

SQL 
*/

select 
    v.customer_id as customer_id,
    count(v.customer_id) as count_no_trans
from Visits v where v.visit_id not in (
    select distinct visit_id from Transactions
) group by customer_id
    
