# Write your MySQL query statement below
select a.gender ,a.day,  sum(b.score_points) as total
from Scores a join Scores b
where a.gender = b.gender and a.day >= b.day
group by a.gender,a.day
order by a.gender, a.day;