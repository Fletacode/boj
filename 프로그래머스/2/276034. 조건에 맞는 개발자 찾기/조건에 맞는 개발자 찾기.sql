select distinct ret.id, ret.email,ret.first_name, ret.last_name
from (select * from DEVELOPERS as dev
inner join SKILLCODES as codes
on codes.code & dev.skill_code
where codes.name = "C#" or codes.name = "Python") as ret
order by ret.id asc;