-- 코드를 입력하세요
SELECT o.animal_id, o.name
from animal_outs o
where animal_id not in (select animal_id from animal_ins where animal_id = o.animal_id)
order by animal_id;