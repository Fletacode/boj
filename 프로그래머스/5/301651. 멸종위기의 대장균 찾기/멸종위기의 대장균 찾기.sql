WITH RECURSIVE family AS (
    
    select id, parent_id, 1 as gen
    from ECOLI_DATA
    where parent_id is null
 
    union all
 
    select  t1.id, t1.parent_id, t2.gen + 1
    from ECOLI_DATA as t1
    inner join family as t2
    on t2.id = t1.parent_id
 )
 
 
select count(A.gen) as "COUNT", A.gen as "GENERATION" from family as A
left join ECOLI_DATA as B
on A.id = B.parent_id
where B.id is null
group by A.gen
order by A.gen;