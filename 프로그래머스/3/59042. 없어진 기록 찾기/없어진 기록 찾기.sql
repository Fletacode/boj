SELECT O.animal_id, O.name
FROM ANIMAL_OUTS O
left join ANIMAL_INS I
on O.animal_id = I.animal_id
where I.animal_id is null
order by O.animal_id