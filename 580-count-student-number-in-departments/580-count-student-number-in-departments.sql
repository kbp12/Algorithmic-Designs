# Write your MySQL query statement below
select a.dept_name, count(b.dept_id) as student_number
from Department a left join student b
on a.dept_id = b.dept_id
group by a.dept_name
order by student_number desc, a.dept_name;