/*
The method to use SQL UPDATE + CASE-WHEN-ELSE-END 
https://stackoverflow.com/questions/12754470/mysql-update-case-when-then-else
# Write your MySQL query statement below

# Wrong testing as the folloing 
# select id,name, case s.sex when "m" then "F" when "f" then "M" else "S" end as sex, salary from Salary s;
# select CASE s.sex WHEN "m" THEN "F" WHEN "f" THEN "M" ELSE "S" END AS "測試" from Salary s;
# The problem need us to use update for current sql table

*/

update Salary set sex = case
    when sex = 'm' then 'f'
    else 'm'
    end;
