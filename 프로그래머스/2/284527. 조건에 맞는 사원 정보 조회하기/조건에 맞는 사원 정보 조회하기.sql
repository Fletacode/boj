select ret.sum_score as 'SCORE',ret.emp_no as 'EMP_NO',
e2.emp_name as 'EMP_NAME', e2.position as 'POSITION', e2.email as 'EMAIL'
from (select g.emp_no as 'emp_no',sum(g.score) 'sum_score'
from HR_EMPLOYEES AS e
inner join HR_GRADE AS g
on e.emp_no = g.emp_no
where g.year = 2022
group by g.emp_no
order by sum(g.score) DESC LIMIT 1) as ret
inner join HR_EMPLOYEES as e2
on ret.emp_no = e2.emp_no

