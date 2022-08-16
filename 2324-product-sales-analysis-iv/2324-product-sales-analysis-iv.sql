# Write your MySQL query statement below
# calculate the total count of each product per user
with user_product_count as (
    select user_id, product_id, sum(quantity) as total_quantity
    from Sales
    group by user_id, product_id
),
# rank the user purchases based on total amount spent on each element
user_spent as (
    select user_id, product_id,
        rank() over (partition by user_id order by total_quantity*price desc) as rk
    from user_product_count inner join Product using(product_id)
)

select user_id, product_id
from user_spent
where rk = 1;