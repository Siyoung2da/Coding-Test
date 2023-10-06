-- 코드를 입력하세요
SELECT year(sales_date) as year, month(sales_date) as month, gender,
    count(distinct o.user_id) as users
from user_info u, online_sale o
where u.user_id = o.user_id and gender is not null
group by year, month, gender
order by year, month, gender;