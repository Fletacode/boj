with recursive A as (

    select 0 as h
 
    union all
    
    select h + 1
    from A
    where h < 23
) 



select A.h as 'HOUR',
    case 
        when ifnull(ANI.animal_id, 1) = 1 then '0'
        else count(*)
    end as 'count'
from ANIMAL_OUTS as ANI
right join A
on HOUR(ANI.DATETIME) = A.h
group by A.h
order by A.h ASC
