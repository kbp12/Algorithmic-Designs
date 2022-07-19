# Write your MySQL query statement below
SELECT a.name as Employee
FROM Employee as a, Employee as b
WHERE a.managerId = b.id AND a.salary > b.salary
;