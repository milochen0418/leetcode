/*
# https://leetcode.com/problems/loan-types
# article https://leetcode.com/problems/loan-types/discuss/4636941/having-group-by-count-distinct
# Write your MySQL query statement below
*/

SELECT user_id
FROM loans
WHERE loan_type = "Refinance" OR loan_type = "Mortgage"
GROUP BY user_id
HAVING COUNT(DISTINCT loan_type) = 2