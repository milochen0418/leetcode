/*
 # https://leetcode.com/problems/the-users-that-are-eligible-for-discount
 # Write your MySQL query statement in the stored procedure.
*/
CREATE PROCEDURE getUserIDs(startDate DATE, endDate DATE, minAmount INT)
BEGIN

    select distinct user_id from Purchases where 
    time_stamp between startDate and endDate and amount>=minAmount
    order by user_id asc
    ;
END