with ret as (select 
             count(distinct U2.user_id) as 'total'
from user_info as U2
where year(U2.joined) = 2021)


select 
year(O.sales_date) as 'YEAR', 
month(O.sales_date) as 'MONTH',
round(count(distinct U.user_id),1) as 'PURCHASED_USERS',
round(count(distinct U.user_id) / ret.total,1) as 'PUCHASED_RATIO'
from user_info as U
inner join online_sale as O
using (user_id)
join ret
where year(U.joined) = 2021
group by year(O.sales_date), month(O.sales_date) 
order by year(O.sales_date), month(O.sales_date)