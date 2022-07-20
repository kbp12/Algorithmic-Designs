# Write your MySQL query statement below
SELECT SalesPerson.name
FROM SalesPerson
WHERE SalesPerson.sales_id NOT IN (
    SELECT Orders.sales_id
    FROM Orders
    WHERE Orders.com_id IN (
        SELECT Company.com_id
        FROM Company
        WHERE Company.name = 'RED'
        )
   )
;




