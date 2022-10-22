select s1.score, (
    select count(distinct s2.score)
    from Scores s2
    where s2.score >= s1.score
) as 'rank'
from scores s1
order by s1.score desc;