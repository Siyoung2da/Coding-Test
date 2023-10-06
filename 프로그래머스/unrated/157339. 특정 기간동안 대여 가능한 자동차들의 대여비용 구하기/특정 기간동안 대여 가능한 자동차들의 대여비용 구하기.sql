-- 코드를 입력하세요
SELECT c.car_id, c.car_type, round(c.daily_fee * 30 * (100-p.discount_rate) / 100) as fee
from CAR_RENTAL_COMPANY_car c, CAR_RENTAL_COMPANY_discount_plan p
where c.car_type = p.car_type 
and p.car_type in ('세단', 'SUV') 
and c.car_id not in (select car_id
                     from CAR_RENTAL_COMPANY_rental_history
                     where end_date >= '2022-11-01' and start_date <= '2022-11-30')
and p.duration_type = '30일 이상' 
and round(c.daily_fee * 30 * (100-p.discount_rate) / 100) < 2000000 
and round(c.daily_fee * 30 * (100-p.discount_rate) / 100) >= 500000
order by fee desc, car_type, car_id desc;