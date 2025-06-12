select 
E.emp_no,
E.EMP_NAME,
case
 when avg(G.score) >= 96 then 'S'
 when avg(G.score) >= 90 then 'A'
 when avg(G.score) >= 80 then 'B'
 else 'C'
end as 'GRADE',
case
 when avg(G.score) >= 96 then E.sal * 0.2
 when avg(G.score) >= 90 then E.sal * 0.15
 when avg(G.score) >= 80 then E.sal * 0.1
 else 0
end as 'BONUS'
from HR_GRADE as G
inner join HR_EMPLOYEES as E
using (emp_no)
group by E.emp_no
