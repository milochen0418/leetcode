/*
# https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times
# Write your MySQL query statement below
*/
/*
Syntax Error
select actor_id, director_id from ActorDirector
where count(timestamp) >= 3 group by actor_id,director_id;
*/
select actor_id, director_id from ActorDirector
group by actor_id,director_id having count(timestamp) >= 3;
