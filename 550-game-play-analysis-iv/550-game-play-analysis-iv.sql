# Write your MySQL query statement below
select round(count(b.player_id)/count(a.player_id),2) as fraction
from (select player_id,min(event_date) as first_login from Activity group by player_id) a left join Activity b
on a.player_id = b.player_id and a.first_login  = b.event_date-1;