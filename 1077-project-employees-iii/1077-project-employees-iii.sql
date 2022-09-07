# Write your MySQL query statement below
select a.project_id, a.employee_id
from Project a join Employee b on a.employee_id = b.employee_id
where (a.project_id, b.experience_years) in (
    select c.project_id, max(d.experience_years)
    from Project c join Employee d on c.employee_id = d.employee_id
    group by c.project_id
)
;