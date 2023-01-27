/*
# https://leetcode.com/problems/rearrange-products-table/
# Write your MySQL query statement below
Input {"headers":{"Products":["product_id","store1","store2","store3"]},"rows":
{"Products":
[[0, 95, 100, 105], 
 [1, 70, null, 80]]}}
 
# select product_id, 'store1' as store, store1 as price from Products;
{"headers": ["product_id", "store", "price"], "values": 
[[0, "store1", 95],
 [1, "store1", 70]]}
 
 # select product_id, 'store2' as store, store2 as price from Products;
{"headers": ["product_id", "store", "price"], "values": 
[[0, "store2", 100], 
 [1, "store2", null]]} 
 
 # select product_id, 'store3' as store, store3 as price from Products;
 {"headers": ["product_id", "store", "price"], "values": 
 [[0, "store3", 105], 
  [1, "store3", 80]]}
*/

select product_id, 'store1' as store, store1 as price from Products 
where store1 is not NULL
UNION
select product_id, 'store2' as store, store2 as price from Products 
where store2 is not NULL
UNION 
select product_id, 'store3' as store, store3 as price from Products
where store3 is not NULL
