--Problem 13: Get all Makes/Count Of Vehicles that manufactures more than 20K Vehicles

-- use Having
select m.Make,count(*)  as NumberOfVehicles from VehicleDetails VD
join Makes m on m.MakeID = VD.MakeID
Group by m.Make
Having (Count(*) >=20000)
order by NumberOfVehicles Desc

-- un Use Having
select * From (
	select m.Make,count(*)  as NumberOfVehicles from VehicleDetails VD
	join Makes m on m.MakeID = VD.MakeID
	Group by m.Make
	
)R1
where (R1.NumberOfVehicles >= 20000 )
order by NumberOfVehicles Desc