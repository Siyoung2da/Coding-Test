-- 코드를 입력하세요
SELECT distinct car_id
from car_rental_company_rental_history
where car_id in (select car_id
                from car_rental_company_car
                where car_type = '세단') 
    and start_date like '2022-10%'
order by car_id desc;