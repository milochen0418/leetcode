/*
# https://leetcode.com/problems/patients-with-a-condition
# Refer : the way to use LOCATE https://www.geeksforgeeks.org/locate-function-in-mysql/
# Write your MySQL query statement below
#select * from Patients where INSTR( conditions , 'DIAB1' ) = 1 OR INSTR( conditions , ' DIAB1' ) > 1;
*/
select * from Patients p where locate(' DIAB1', p.conditions)>1 OR locate('DIAB1', p.conditions)=1;


 