# Write your MySQL query statement below
with table1 as(
    select *, row_number() over(partition by Company order by Salary) as rno, count(id) over(partition by Company) as cnt
    from Employee
)
select id, company, salary
from table1
where rno between cnt/2.0 and cnt/2.0 +1;