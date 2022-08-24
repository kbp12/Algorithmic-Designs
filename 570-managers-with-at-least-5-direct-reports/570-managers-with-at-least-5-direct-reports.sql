with temp as(
    select managerId from Employee group by managerId having count(managerId)>4
)
select a.name
from Employee a join temp t
on a.Id = t.managerId;
 