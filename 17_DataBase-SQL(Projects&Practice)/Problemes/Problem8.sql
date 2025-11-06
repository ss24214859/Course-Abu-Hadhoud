--Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside it, then calculate it's percentage


	select m.Make , F.FuelTypeName ,Count(*) NumberOfVehicles 
	from VehicleDetails VD
	join Makes M on M.MakeID = VD.MakeID
	join FuelTypes F on F.FuelTypeID = VD.FuelTypeID
	where (Year Between 1950 And 2000)
	Group by m.Make , F.FuelTypeName
	order by m.Make Asc

