/*
# Write your MySQL query statement below
# https://leetcode.com/problems/duplicate-emails
*/
SELECT DISTINCT a.email AS Email FROM Person a LEFT JOIN Person b ON a.id <> b.id WHERE a.email = b.email;
