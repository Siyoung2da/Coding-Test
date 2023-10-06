-- 코드를 입력하세요
SELECT member_name, review_text, date_format(review_date, '%Y-%m-%d') as review_date
from member_profile m, rest_review r
where m.member_id = r.member_id
and m.member_id = (select member_id
                    from rest_review
                    group by member_id
                    order by count(member_id) desc
                   limit 1)
order by review_date, review_text;