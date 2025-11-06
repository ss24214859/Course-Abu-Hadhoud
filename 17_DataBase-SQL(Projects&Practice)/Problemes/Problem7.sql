--Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside it, then calculate it's percentage

select  * ,  cast (R1.NumberOfVehicles as float )/cast( R1.TotalVehicles as float)  as Perc From 
(
	select m.Make,Count(*) NumberOfVehicles ,(select count(*) from VehicleDetails) as TotalVehicles
	from VehicleDetails VD
	join Makes M on M.MakeID = VD.MakeID
	where (Year Between 1950 And 2000)
	Group by m.Make
	
)R1
order by NumberOfVehicles Desc

