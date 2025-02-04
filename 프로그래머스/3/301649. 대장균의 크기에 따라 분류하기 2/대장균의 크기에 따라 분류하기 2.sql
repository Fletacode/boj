select  ret.id as "ID",
    case
        when len <= 0.25 then "CRITICAL"
        when len <= 0.5 then "HIGH"
        when len <= 0.75 then "MEDIUM"
        else "LOW"
    end as "COLONY_NAME"
from (select A.id,
      percent_rank() over(order by A.size_of_colony DESC) as len
from ECOLI_DATA as A) as ret
order by ret.id