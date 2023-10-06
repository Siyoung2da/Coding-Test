-- 코드를 입력하세요
SELECT year(sales_date) as year,
    month(sales_date) as month,
    count(distinct o.user_id) as puchased_users,
    round(count(distinct o.user_id) / (select count(*) from user_info where joined like '2021%'), 1) as puchased_ratio
from user_info u, online_sale o
where u.user_id = o.user_id and joined like '2021%'
group by year, month
order by year, month;