/*
# Write your MySQL query statement below
# https://leetcode.com/problems/find-users-with-valid-e-mails
*/
select * from Users where 
REGEXP_LIKE (mail,'^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$')

