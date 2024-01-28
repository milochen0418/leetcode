/*
# https://leetcode.com/problems/loan-types
# Write your MySQL query statement below
*/

SELECT user_id
FROM loans
WHERE loan_type = "Refinance" OR loan_type = "Mortgage"
GROUP BY user_id
HAVING COUNT(DISTINCT loan_type) = 2