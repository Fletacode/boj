with max_fish as (select A.fish_type, max(A.length) as "length"
from FISH_INFO AS A
group by A.fish_type)


select A.id, B.fish_name, A.length
from fish_info as A
inner join fish_name_info as B
on A.fish_type = B.fish_type
where (A.fish_type, A.length) in (select * from max_fish)

