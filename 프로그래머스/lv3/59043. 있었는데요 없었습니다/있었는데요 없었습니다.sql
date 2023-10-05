-- 코드를 입력하세요
SELECT animal_id, name
from animal_ins
where animal_id in (select animal_id 
                    from animal_outs
                    where animal_id = animal_ins.animal_id and datetime < animal_ins.datetime)
order by datetime;