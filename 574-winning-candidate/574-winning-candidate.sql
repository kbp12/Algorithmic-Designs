# Write your MySQL query statement below
with temp as(
    select candidateId from Vote group by candidateId order by count(candidateId) desc limit 1 
)
select name 
from Candidate c join temp t
on c.id = t.candidateId;