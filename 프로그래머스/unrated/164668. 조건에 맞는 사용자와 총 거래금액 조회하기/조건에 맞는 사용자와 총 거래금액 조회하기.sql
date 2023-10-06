-- 코드를 입력하세요
SELECT user_id, nickname, sum(price) as total_sales
from used_goods_user u, used_goods_board b
where u.user_id = b.writer_id and status = 'done'
group by writer_id 
having sum(price) >= 700000
order by total_sales;