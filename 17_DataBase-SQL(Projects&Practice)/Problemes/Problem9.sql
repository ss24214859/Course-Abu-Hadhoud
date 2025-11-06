 
--Problem 9: Get all vehicles that runs with GAS

select VD.* , F.FuelTypeName 
from VehicleDetails VD
		join FuelTypes F on F.FuelTypeID = VD.FuelTypeID
where F.FuelTypeName = N'GAS'
