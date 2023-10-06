-- 코드를 입력하세요
SELECT history_id, round(sum(daily_fee * (timestampdiff(day, start_date, end_date) + 1) * (1 - ifnull(discount_rate, 0) / 100)), 0) as fee
from car_rental_company_car c
left join car_rental_company_rental_history h on c.car_id = h.car_id
left join car_rental_company_discount_plan p on c.car_type = p.car_type
    and 
        duration_type = (case 
            when timestampdiff(day, start_date, end_date) + 1 between 7 and 29 then "7일 이상"
            when timestampdiff(day, start_date, end_date) + 1 between 30 and 89 then "30일 이상"
            when timestampdiff(day, start_date, end_date) +1 >= 90 then "90일 이상"
            else "" end)
where c.car_type = '트럭'
group by history_id
order by fee desc, history_id desc;
