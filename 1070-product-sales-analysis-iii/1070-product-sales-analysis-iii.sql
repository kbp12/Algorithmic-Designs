# Write your MySQL query statement below
select a.product_id, a.year as first_year, a.quantity, a.price
from Sales a
where (a.product_id, a.year) IN (
    select product_id, min(year) as year
    from sales
    group by product_id
)
;