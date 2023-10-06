-- 코드를 입력하세요
SELECT distinct car_id, '대여중' as availability
from car_rental_company_rental_history
where start_date < '2022-10-17' and end_date >= '2022-10-16'
union all
SELECT distinct car_id, '대여 가능' as availability
from car_rental_company_rental_history
where car_id not in (select car_id
                     from car_rental_company_rental_history
                     where start_date < '2022-10-17' and end_date >= '2022-10-16')
order by car_id desc;