/*
 # https://leetcode.com/problems/the-number-of-users-that-are-eligible-for-discount/
 # Write your MySQL query statement below.
*/
CREATE FUNCTION getUserIDs(startDate DATE, endDate DATE, minAmount INT) RETURNS INT
BEGIN

  RETURN (   
    select count(distinct user_id) from Purchases where 
    time_stamp between startDate and endDate and amount>=minAmount
    order by user_id asc
  );
END