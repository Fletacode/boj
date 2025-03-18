select count(*) as "FISH_COUNT", B.fish_name from FISH_INFO as A
inner join FISH_NAME_INFO as B
on A.fish_type = B.fish_type
group by B.fish_name
order by count(*) DESC