# Write your MySQL query statement below
select a.sale_date , sum(a.sold_num)-sum(b.sold_num) as diff
from Sales a join Sales b
where a.sale_date = b.sale_date and a.fruit = 'apples' and b.fruit = 'oranges'
group by a.sale_date;