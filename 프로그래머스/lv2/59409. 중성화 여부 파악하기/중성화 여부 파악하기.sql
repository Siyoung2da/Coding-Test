-- 코드를 입력하세요
# SELECT animal_id, name, 'O' as 중성화
# from animal_ins
# where sex_upon_intake like 'neutered%' or sex_upon_intake like 'spayed%'
# union all
# select animal_id, name, 'X' as 중성화
# from animal_ins
# where animal_id not in (select animal_id 
#                     from animal_ins
#                     where sex_upon_intake like 'neutered%' or sex_upon_intake like 'spayed%')
# order by animal_id;

select animal_id, 
    name,
    if(sex_upon_intake like 'neutered%' or sex_upon_intake like 'spayed%', 'O', 'X') as 중성화
from animal_ins
order by animal_id;
