-- 코드를 입력하세요
# set @price := -10000;

# SELECT (@price := @price + 10000) price_group, 
#     (select count(*) 
#      from product
#      where price >= @price and price < @price + 10000) as products
# from product
# order by @price;

select truncate(price, -4) as price_group, count(*) as products
from product
group by price_group
order by price_group;