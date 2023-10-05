-- 코드를 입력하세요
SELECT product_code, sum(sales_amount) * price as sales
from product p, offline_sale o
where p.product_id = o.product_id
group by p.product_id
order by sales desc, product_code;