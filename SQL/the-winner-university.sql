/*
https://leetcode.com/problems/the-winner-university/
The refer to use the CASE,WHEN,ELSE,END https://www.w3schools.com/sql/func_mysql_case.asp
# Write your MySQL query statement below
*/
select (
    case 

    when    
    (select count(score) from NewYork where score >=90)>
    (select count(score) from California where score >=90) 
    then 'New York University'

    when
    (select count(score) from NewYork where score >=90)<
    (select count(score) from California where score >=90)
    then 'California University'

    else 
        'No Winner'
    end
) 
as winner;