# Write your MySQL query statement below
select a.player_id, a.event_date, sum(b.games_played) as games_played_so_far
from activity a join activity b
on a.player_id = b.player_id
where a.player_id = b.player_id and a.event_date>=b.event_date
group by a.player_id, a.event_date
order by a.player_id, a.event_date;
    