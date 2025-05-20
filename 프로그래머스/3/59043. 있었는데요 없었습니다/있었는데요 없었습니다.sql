select I.animal_id, I.name
from ANIMAL_INS I
inner join ANIMAL_OUTS O
on I.animal_id = O.animal_id
where I.DATETIME > O.DATETIME
order by I.DATETIME ASC