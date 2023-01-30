/*
# https://leetcode.com/problems/average-time-of-process-per-machine
# Write your MySQL query statement below

Input 
{"headers":{"Activity":["machine_id","process_id","activity_type","timestamp"]},"rows":{"Activity":[[0,0,"start",0.712],
[0,0,"end",1.52],
[0,1,"start",3.14],
[0,1,"end",4.12],
[1,0,"start",0.55],
[1,0,"end",1.55],
[1,1,"start",0.43],
[1,1,"end",1.42],
[2,0,"start",4.1],
[2,0,"end",4.512],
[2,1,"start",2.5],
[2,1,"end",5]]}}
We use the following SQL statement first

select a.machine_id  as machine_id, 
a.process_id as process_id, b.timestamp - a.timestamp as processing_time
from Activity a , Activity b where 
    a.machine_id=b.machine_id and 
    a.process_id=b.process_id and
    a.activity_type='start' and
    b.activity_type='end'
    
Output:
{"headers": ["machine_id", "process_id", "processing_time"], "values": 
[[0, 0, 0.8079999685287476], 
 [0, 1, 0.9799997806549072], 
 [1, 0, 0.9999999403953552], 
 [1, 1, 0.9899999499320984], 
 [2, 0, 0.4120001792907715], 
 [2, 1, 2.5]]}
 
Then we need to get average group by a.process_id and get 3 float point .000 by round(..., 3)
Thus we have the following final solution 
*/


select a.machine_id  as machine_id, 
round(avg(b.timestamp - a.timestamp),3) as processing_time
from Activity a , Activity b where 
    a.machine_id=b.machine_id and 
    a.process_id=b.process_id and
    a.activity_type='start' and
    b.activity_type='end'
group by a.machine_id
