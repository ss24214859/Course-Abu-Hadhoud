--Get percentage of vehicles that has no doors specified
select ( 
		cast((select count(*) From VehicleDetails 
			  where NumDoors is Null )as float)
	/
		cast((select count(*) From VehicleDetails )as float)
	) as PercOfNoSpecifiedDoors