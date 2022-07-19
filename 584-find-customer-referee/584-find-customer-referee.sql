# Write your MySQL query statement below
SELECT Customer.name
FROM Customer
WHERE Customer.id NOT IN 
    (
        SELECT Customer.id
        FROM Customer
        WHERE Customer.referee_id = 2
    )
;