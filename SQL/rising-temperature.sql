/*
# https://leetcode.com/problems/rising-temperature/
# Write your MySQL query statement below
# Use datediff to find out previous day and check yesterday's temperature 
*/
select weather.id AS 'Id'
from weather join weather tmp on 
datediff(weather.recordDate, tmp.recordDate) = 1 and weather.Temperature > tmp.Temperature;