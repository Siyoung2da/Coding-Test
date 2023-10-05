-- 코드를 입력하세요
SELECT name, datetime
from animal_ins i
where animal_id not in (select animal_id
                       from animal_outs
                       where animal_id = i.animal_id)
order by datetime
limit 3;