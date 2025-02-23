with recursive ret as (
    select A.id, A.parent_id, 1 as gen
    from ECOLI_DATA as A
    where IFNULL(A.parent_id,0) = 0
    
    union all
    
    select T.id, T.parent_id, ret.gen + 1
    from ECOLI_DATA as T
    inner join ret
    on T.parent_id = ret.id
)



select count(*) as 'COUNT', ret.gen as 'GENERATION' from ret
left join ECOLI_DATA as A
on ret.id = A.parent_id
where A.parent_id is null
group by A.parent_id, ret.gen
order by ret.gen ASC
