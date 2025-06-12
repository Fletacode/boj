select 
D.DEPT_ID,
D.DEPT_NAME_EN,
round(avg(E.sal),0) AS 'AVG_SAL'
from HR_DEPARTMENT as D
inner join HR_EMPLOYEES as E
using (dept_id)
group by D.dept_name_en, D.dept_id
order by AVG_SAL DESC
