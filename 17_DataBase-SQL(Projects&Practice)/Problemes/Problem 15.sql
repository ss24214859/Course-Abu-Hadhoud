  --Problem 15: Get all Makes with make Ends with 'W'

Select Make 
From Makes
where (Make Like '%W')

select m.Make,count(*)  as NumberOfVehicles 
from VehicleDetails VD
		join Makes m on m.MakeID = VD.MakeID
Group by m.Make
Having (m.Make Like '%W')
order by NumberOfVehicles Desc
