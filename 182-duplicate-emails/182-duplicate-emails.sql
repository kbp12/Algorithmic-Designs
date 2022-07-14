# Write your MySQL query statement below
SELECT email as Email 
FROM (
        SELECT email, count(email) as num
        FROM Person
        GROUP BY email
    ) as statistic
    WHERE num>1
    ;