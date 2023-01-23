/*
https://leetcode.com/problems/form-a-chemical-bond
# Write your MySQL query statement below
#select symbol as metal from Elements where type="Metal";
#select symbol as nonmetal from Elements where type="Nonmetal";
*/
select a.symbol as metal, b.symbol as nonmetal 
from Elements a, Elements b
where a.type='Metal' and b.type='Nonmetal';