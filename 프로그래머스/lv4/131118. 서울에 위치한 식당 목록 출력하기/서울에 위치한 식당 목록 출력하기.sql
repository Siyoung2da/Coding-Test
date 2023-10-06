-- 코드를 입력하세요
SELECT i.rest_id, rest_name, food_type, favorites, address, round(avg(review_score), 2) as score
from rest_info i, rest_review r
where i.rest_id = r.rest_id
and address like '서울%'
group by r.rest_id
order by score desc, favorites desc;