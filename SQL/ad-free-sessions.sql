/*
# https://leetcode.com/problems/ad-free-sessions/
# Write your MySQL query statement below
At the first, we need to find out session_id is match to ad_id

Input 
{"headers":{"Playback":["session_id","customer_id","start_time","end_time"],"Ads":["ad_id","customer_id","timestamp"]},"rows":{"Playback":[[1,1,1,5],[2,1,15,23],[3,2,10,12],[4,2,17,28],[5,2,2,8]],"Ads":[[1,1,5],[2,2,17],[3,2,20]]}}

select a.ad_id, p.session_id from 
Ads a, Playback p where a.customer_id=p.customer_id 
and a.timestamp>=p.start_time and a.timestamp <= p.end_time;

Output 
{"headers": ["ad_id", "session_id"], "values": [[1, 1], [3, 4], [2, 4]]}

Expected
{"headers": ["session_id"], "values": [[2], [3], [5]]}

And then we can use NOT IN for above SQL. 
That's why the following is the answer
*/
select session_id from Playback where session_id not in 
(
    select p.session_id from 
    Ads a, Playback p where a.customer_id=p.customer_id 
    and a.timestamp>=p.start_time and a.timestamp <= p.end_time
)
