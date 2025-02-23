with FE as (
select sum(code) as 'code'
    from SKILLCODES
    where category = "Front End"),
    
RET as (
select 
    case
        when (D.skill_code & (select code from FE) > 0 and 
              D.skill_code & (select code from SKILLCODES where name = "Python") > 0 )
        then "A"
        when D.skill_code & (select code from SKILLCODES where name = "C#") > 0
        then "B"
        when D.skill_code & (select code from FE) > 0 then "C"
    end as "GRADE",
    D.id,
    D.email
    from DEVELOPERS as D
)

select ret.grade, ret.id, ret.email from ret
where ret.grade is not null
order by ret.grade, ret.id