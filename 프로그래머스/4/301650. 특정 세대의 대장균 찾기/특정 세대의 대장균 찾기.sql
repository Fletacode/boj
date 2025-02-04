select C.id from ECOLI_DATA as C
inner join 
(select A.id from ECOLI_DATA as A
 
inner join
 
(select id
from ECOLI_DATA
where IFNULL(parent_id,0) = 0) as gen1
 
on A.parent_id = gen1.id) as gen2

on C.parent_id = gen2.id
order by C.id ASC;
