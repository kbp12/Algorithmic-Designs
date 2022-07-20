# Write your MySQL query statement below
SELECT Cinema.*
FROM Cinema
WHERE Cinema.description <> 'boring' AND MOD(Cinema.id,2) = 1
ORDER BY Cinema.rating DESC
;