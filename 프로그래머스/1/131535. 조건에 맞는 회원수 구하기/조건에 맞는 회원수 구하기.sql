select count(user_id)
from user_info
where YEAR(joined) = 2021
and
(age >= 20 and age <= 29);

