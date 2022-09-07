# Write your MySQL query statement below
select a.project_id, round(avg(b.experience_years),2) as average_years
from Project a join Employee b
where a.employee_id = b.employee_id
group by a.project_id;