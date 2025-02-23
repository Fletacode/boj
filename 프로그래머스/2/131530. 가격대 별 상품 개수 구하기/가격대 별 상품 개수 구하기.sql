SELECT floor(P.price / 10000) * 10000 as 'price', count(P.price) as 'count'
from PRODUCT as P
group by floor(P.price / 10000)
order by price


