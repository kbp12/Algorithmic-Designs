# Write your MySQL query statement below
select  avg(n.num) as median
from Numbers n
where n.frequency >= abs((select sum(frequency) from Numbers where num<=n.num) -
                         (select sum(frequency) from Numbers where num>=n.num))