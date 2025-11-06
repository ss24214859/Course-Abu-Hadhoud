  --Problem 14: Get all Makes with make starts with 'B'

Select Make 
From Makes
where (Make Like 'B%')

select m.Make,count(*)  as NumberOfVehicles 
from VehicleDetails VD
		join Makes m on m.MakeID = VD.MakeID
Group by m.Make
Having (m.Make Like 'B%')
order by NumberOfVehicles Desc
