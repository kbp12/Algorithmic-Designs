# Write your MySQL query statement below
with temp as(
    select a.invoice_id, sum(a.quantity*b.price) as p
    from Purchases a left join Products b on a.product_id = b.product_id
    group by a.invoice_id
    order by p desc, a.invoice_id asc
    limit 1
)
select a.product_id, a.quantity, a.quantity*b.price as price
from Purchases a left join Products b
on a.product_id = b.product_id
where a.invoice_id in (
    select invoice_id from temp    
);