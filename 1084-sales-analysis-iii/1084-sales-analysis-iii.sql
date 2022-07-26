# Write your MySQL query statement below
select a.product_id, b.product_name
from Sales a Join Product b
on a.product_id = b.product_id
group by a.product_id
having  min(sale_date) >= CAST('2019-01-01' as date) and
       max(sale_date) <= CAST('2019-03-31' as date)