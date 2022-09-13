# Write your MySQL query statement below
select b.book_id, b.name
from books b left join
    (select book_id, sum(quantity) as book_sold
    from Orders 
    where dispatch_date between '2018-06-23' and '2019-06-23'
    group by book_id) t
on b.book_id = t.book_id
where b.available_from < '2019-05-23'
and (book_sold is null or book_sold <10)
order by b.book_id;