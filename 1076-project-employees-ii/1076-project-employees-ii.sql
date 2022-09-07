# Write your MySQL query statement below
select project_id
from Project
group by project_id
having count(employee_id) = (select count(employee_id) as temp from Project group by project_id order by temp desc limit 1)
;