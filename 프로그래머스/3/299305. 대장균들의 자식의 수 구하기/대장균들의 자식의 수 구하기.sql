select  origin.id, IFNULL(ret_cnt.cnt,0) as CHILD_COUNT
from ECOLI_DATA as origin
left join (select ret.id ,count(*) as cnt from (select parent.id
from ECOLI_DATA as parent
inner join ECOLI_DATA as child
on parent.id = child.parent_id) as ret
group by ret.id
having ret.id) as ret_cnt
on origin.id = ret_cnt.id