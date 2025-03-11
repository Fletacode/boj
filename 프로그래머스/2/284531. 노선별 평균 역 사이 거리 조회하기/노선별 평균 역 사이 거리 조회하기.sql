select S.route as "ROUTE", 
CONCAT(ROUND(SUM(S.d_between_dist),1), "km") as "TOTAL_DISTANCE", 
CONCAT(ROUND(AVG(S.d_between_dist),2),"km")  as "AVERAGE_DISTANCE"
from SUBWAY_DISTANCE as S
group by S.route
order by ROUND(SUM(S.d_between_dist),2) DESC