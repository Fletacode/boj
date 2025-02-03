select A.id,
       case 
    when A.SIZE_OF_COLONY <= 100 then "LOW"
    when A.SIZE_OF_COLONY BETWEEN 101 and 1000 then "MEDIUM"
    when A.SIZE_OF_COLONY > 1000 then "HIGH" 
       end as size
from ECOLI_DATA as A
