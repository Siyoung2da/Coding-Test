-- 코드를 입력하세요
SELECT o.animal_id, o.name
from animal_outs o, animal_ins i
where o.animal_id = i.animal_id
order by timestampdiff(day, i.datetime, o.datetime) desc
limit 2;