--Get All Makes that have manufactured more than 12000 Vehicles in years 1950 to 2000

-- Without Having
with temp As
(
	select m.Make,Count(*) NumberOfVehicles from VehicleDetails VD
	join Makes M on M.MakeID = VD.MakeID
	where (Year Between 1950 And 2000)
	Group by m.Make
)
Select * From temp
where NumberOfVehicles >= 12000
order by NumberOfVehicles Desc

--another SL Without Having   Abo Hadhoud  

Select * From 
(
		select m.Make,Count(*) NumberOfVehicles from VehicleDetails VD
		join Makes M on M.MakeID = VD.MakeID
		where (Year Between 1950 And 2000)
		Group by m.Make
) R1
where R1.NumberOfVehicles >= 12000
order by NumberOfVehicles Desc

-- Best SL after use Having
 

select m.Make,Count(*) NumberOfVehicles from VehicleDetails VD
join Makes M on M.MakeID = VD.MakeID
where (Year Between 1950 And 2000)
Group by m.Make
Having Count(*) >= 12000
order by NumberOfVehicles Desc




