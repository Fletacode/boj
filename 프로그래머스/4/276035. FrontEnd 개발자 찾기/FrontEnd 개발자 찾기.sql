select 
DISTINCT D.ID,
D.EMAIL,
D.FIRST_NAME,
D.LAST_NAME
from developers as D
inner join skillcodes as C
on (D.skill_code & C.code) >= 1
where C.category = 'Front End'
order by D.id ASC