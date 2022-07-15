# Write your MySQL query statement below
SELECT 
    Customers.name as Customers
FROM 
    Customers
WHERE
    Customers.Id NOT IN
    (
        SELECT 
            Orders.customerId
        FROM 
            Orders
    )
;