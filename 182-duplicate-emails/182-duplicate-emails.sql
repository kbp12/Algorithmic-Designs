# Write your MySQL query statement below
SELECT DISTINCT a.email as Email
FROM Person a, Person b
WHERE a.id <> b.id
    AND a.email = b.email;