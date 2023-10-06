-- 코드를 입력하세요
SELECT j.flavor
from first_half f, july j
where f.flavor = j.flavor
group by j.flavor
order by sum(f.total_order + j.total_order) desc
limit 3;