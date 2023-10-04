-- 코드를 입력하세요
SELECT b.author_id, a.author_name, b.category, sum(b.price * s.sales) as total_sales
from book b, book_sales s, author a
where b.book_id = s.book_id and a.author_id = b.author_id and sales_date like '2022-01%'
group by b.author_id, b.category
order by b.author_id, category desc;