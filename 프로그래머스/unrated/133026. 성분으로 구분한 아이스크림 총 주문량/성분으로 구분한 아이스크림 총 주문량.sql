-- 코드를 입력하세요
SELECT ingredient_type, sum(total_order) as total_order
from first_half f, icecream_info i
where f.flavor = i.flavor
group by ingredient_type
order by total_order;
