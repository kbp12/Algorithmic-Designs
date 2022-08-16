# Write your MySQL query statement below
 select product_id, sum(quantity) as total_quantity
 from Sales left join Product
 using (product_id)
 group by product_id;