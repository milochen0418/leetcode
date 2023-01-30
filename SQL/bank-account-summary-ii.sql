/*
# https://leetcode.com/problems/bank-account-summary-ii/
# Write your MySQL query statement below
Input
{"headers": {"Users": ["account", "name"], "Transactions": 
["trans_id", "account", "amount", "transacted_on"]}, "rows": {"Users": 
[[900001, "Alice"], 
 [900002, "Bob"], 
 [900003, "Charlie"]], "Transactions": 
 [
 [1, 900001, 7000, "2020-08-01"], 
 [2, 900001, 7000, "2020-09-01"],
 [3, 900001, -3000, "2020-09-02"],
 [4, 900002, 1000, "2020-09-12"],
 [5, 900003, 6000, "2020-08-07"],
 [6, 900003, 6000, "2020-09-07"],
 [7, 900003, -4000, "2020-09-11"]]}}

SQL 
select 
    t.account as account, u.
    u.name as name, 
    t.amount as amount 
from Transactions t left join Users u ont.account = u.account

Output 
{"headers": ["account", "name", "amount"], "values": 
[[900001, "Alice", 7000],
 [900001, "Alice", 7000], 
 [900001, "Alice", -3000],
 [900002, "Bob", 1000],
 [900003, "Charlie", 6000],
 [900003, "Charlie", 6000],
 [900003, "Charlie", -4000]]}

Expected
{"headers": ["NAME", "BALANCE"], "values": [
 ["Alice", 11000]]}

Thus, we can add group by to figure out sum(amount) and then get the balance>10000

*/
select 
    u.name as name, 
    sum(t.amount) as balance 
from Transactions t left join Users u on t.account = u.account
group by t.account having balance>10000