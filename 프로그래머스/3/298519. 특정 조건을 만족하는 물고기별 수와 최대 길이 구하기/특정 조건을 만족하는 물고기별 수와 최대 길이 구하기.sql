with FT as (select A.fish_type from FISH_INFO as A
group by A.fish_type
having avg(A.length) >= 33)


select count(*) as "FISH_COUNT", max(B.length) as "MAX_LENGTH", B.fish_type as "FISH_TYPE"
from FT
inner join FISH_INFO AS B
on FT.fish_type = B.fish_type
group by B.fish_type
order by B.fish_type