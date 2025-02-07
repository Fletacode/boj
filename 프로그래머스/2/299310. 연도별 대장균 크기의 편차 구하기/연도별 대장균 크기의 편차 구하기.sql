select B.year as "YEAR" ,
(B.max_size - A.size_of_colony) as "YEAR_DEV",
A.id
from ECOLI_DATA as A
inner join
(select max(SIZE_OF_COLONY) as 'max_size' , YEAR(DIFFERENTIATION_DATE) as "year" 
 from ECOLI_DATA
group by YEAR(DIFFERENTIATION_DATE) ) as B
on YEAR(A.DIFFERENTIATION_DATE) = B.year
order by B.year ASC , 
(max_size - A.size_of_colony) ASC