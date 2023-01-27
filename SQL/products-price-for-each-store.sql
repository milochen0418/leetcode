# Write your MySQL query statement below
/*
# https://leetcode.com/problems/products-price-for-each-store
select product_id,
case when store ='store1' then price end as store1,
case when store ='store2' then price end as store2,
case when store ='store3' then price end as store3
from Products

Input 
{"headers":{"Products":["product_id","store","price"]},"rows":{"Products":
[["0","store1","95"],
 ["0","store3","105"],
 ["0","store2","100"],
 ["1","store1","70"],
 ["1","store3","80"]]}}

Output:
{"headers": ["product_id", "store1", "store2", "store3"], "values": [
[0, 95, null, null], 
[0, null, null, 105],
[0, null, 100, null], 
[1, 70, null, null], 
[1, null, null, 80]]} 

The usage of SUM here
sum(null,null,null) is null
sum(null,3,40) is 43
*/


select product_id,
sum(case when store ='store1' then price end) as store1,
sum(case when store ='store2' then price end) as store2,
sum(case when store ='store3' then price end) as store3
from Products
group by product_id