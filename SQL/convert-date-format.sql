/*
 # https://leetcode.com/problems/convert-date-format/ 
 # Write your MySQL query statement below
 # MySQL DATE_FORMAT refer  https://www.w3resource.com/mysql/date-and-time-functions/mysql-date_format-function.php
*/
select date_format(day, "%W, %M %e, %Y") as day from Days;