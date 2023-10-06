-- 코드를 입력하세요
SELECT month(start_date) as month, car_id, count(car_id) as records
from car_rental_company_rental_history
where car_id in (select car_id
                from car_rental_company_rental_history
                where start_date >= '2022-08-01' and start_date <= '2022-10-31'
                group by car_id having count(car_id) >= 5)
and start_date >= '2022-08-01' and start_date <= '2022-10-31'
group by month, car_id
order by month, car_id desc;