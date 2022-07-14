# Write your MySQL query statement below
SELECT firstname, lastname, city, state
FROM Person left join Address
ON Person.personId = Address.personId;