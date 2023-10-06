-- 코드를 입력하세요
SELECT category, sum(sales) as total_sales
from book b, book_sales s
where b.book_id = s.book_id and sales_date like '2022-01%'
group by category
order by category