-- 코드를 입력하세요
SELECT p.product_id, product_name, sum(amount) * price as total_sales
from food_product p, food_order o
where p.product_id = o.product_id
and produce_date like '2022-05%'
group by p.product_id
order by total_sales desc, p.product_id;
