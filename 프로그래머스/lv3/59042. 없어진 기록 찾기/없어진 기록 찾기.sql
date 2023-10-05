-- 코드를 입력하세요
# SELECT o.animal_id, o.name
# from animal_outs o
# where animal_id not in (select animal_id from animal_ins where animal_id = o.animal_id)
# order by animal_id;

select animal_outs.animal_id, animal_outs.name
from animal_outs left join animal_ins on animal_outs.animal_id = animal_ins.animal_id
where animal_ins.animal_id is null;