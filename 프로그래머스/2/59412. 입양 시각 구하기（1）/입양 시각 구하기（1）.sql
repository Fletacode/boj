select * from (SELECT  HOUR(A.datetime) as 'HOUR' ,count(*) as 'COUNT'
from ANIMAL_OUTS as A
group by HOUR(A.datetime)) as B
where B.HOUR between 9 and 19
order by B.HOUR ASC
