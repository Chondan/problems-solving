with T as 
(
	select 
	id, 
	lag(recordDate,1) over(order by recordDate) as predate,
	lag(Temperature,1) over(order by recordDate) as pretemp
	from
	Weather	
)

select W.id 
from Weather W 
join T 
on T.id = W.id 
and datediff(W.recordDate, T.predate) = 1 
and W.Temperature > T.pretemp;