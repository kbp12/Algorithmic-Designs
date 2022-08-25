# Write your MySQL query statement below
with table1 as(
    select question_id, sum(case when action="show" then 1 else 0 end) as num_show,
    sum(case when action = "answer" then 1 else 0 end) as num_answer
    from SurveyLog
    group by question_id
)
select question_id as survey_log
from table1
order by (num_answer/num_show) desc, question_id asc
limit 1;
