# Write your MySQL query statement below
with tab as(
    select c.customer_id,c.salesperson_id, sum(d.price) as summ
    from Customer c left join Sales d
    on c.customer_id = d.customer_id
    group by c.salesperson_id
)
select a.salesperson_id, a.name, coalesce(b.summ,0) as total
from Salesperson a left join tab b
on a.salesperson_id = b.salesperson_id
group by salesperson_id;