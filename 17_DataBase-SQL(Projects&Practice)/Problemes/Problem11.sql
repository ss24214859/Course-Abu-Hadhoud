  
  --Problem 11: Get Total Makes that runs with GAS

	select  count(distinct m.Make )TotalMakesRunOnGas
	from VehicleDetails VD
	join Makes M on M.MakeID = VD.MakeID
	join FuelTypes F on F.FuelTypeID = VD.FuelTypeID
	where (F.FuelTypeName = N'GAS')


	-- Abo HadHoud SL
select count(*) TotalMakesRunOnGas from
(
	select distinct  m.Make , F.FuelTypeName 
	from VehicleDetails VD
	join Makes M on M.MakeID = VD.MakeID
	join FuelTypes F on F.FuelTypeID = VD.FuelTypeID
	where (F.FuelTypeName = N'GAS')
) R1
