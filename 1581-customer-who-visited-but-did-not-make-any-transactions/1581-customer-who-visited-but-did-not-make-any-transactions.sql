# Write your MySQL query statement below
select a.customer_id, count(a.customer_id) as count_no_trans
from Visits a
where a.visit_id not in (
    select visit_id 
    from Transactions
)
group by a.customer_id
order by count_no_trans;