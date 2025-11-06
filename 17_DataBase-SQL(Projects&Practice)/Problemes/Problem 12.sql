--Problem 12: Count Vehicles by make and order them by NumberOfVehicles from high to low.

select m.Make,count(*)  as NumberOfVehicles from VehicleDetails VD
join Makes m on m.MakeID = VD.MakeID
Group by m.Make
order by NumberOfVehicles Desc