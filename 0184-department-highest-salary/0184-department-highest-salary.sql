# Write your MySQL query statement below
select d.name as "Department", e.name as "Employee", e.salary as "Salary"
from Employee e join Department d on e.departmentId = d.id
where  (e.departmentId , e.salary) in (select ee.departmentId , max(ee.salary) from Employee ee group by ee.departmentId)
;