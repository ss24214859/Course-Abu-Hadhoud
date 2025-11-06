  
  --Problem 10: Get all Makes that runs with GAS

	select distinct m.Make , F.FuelTypeName 
	from VehicleDetails VD
	join Makes M on M.MakeID = VD.MakeID
	join FuelTypes F on F.FuelTypeID = VD.FuelTypeID
	where (F.FuelTypeName = N'GAS')
	order by m.Make Asc

