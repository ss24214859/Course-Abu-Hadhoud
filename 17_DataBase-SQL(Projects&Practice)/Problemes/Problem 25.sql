-- Get  make and vehicles that the engine contains 'OHV' and have Cylinders = 4

Select  m.Make,VD.* From Makes m
join VehicleDetails VD on VD.MakeID = m.MakeID
where (Engine like '%OHV%') And (Engine_Cylinders = 4)
