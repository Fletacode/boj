select id , email, first_name, last_name
from DEVELOPER_INFOS as info
where info.skill_1 = "Python"
or info.skill_2 = "Python"
or info.skill_3 = "Python"
order by id