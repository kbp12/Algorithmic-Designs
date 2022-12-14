# Write your MySQL query statement below
select t.request_at as Day , round( count(
    case 
        when t.status != "completed" then 1
        else NULL
        end
) / count(*) , 2) as "Cancellation Rate"
from Trips t 
where t.client_id in (select users_id from Users where banned = "No") and t.driver_id in (select users_id from Users where banned = "No") and t.request_at >= "2013-10-01" and t.request_at <= "2013-10-03"
group by Day;