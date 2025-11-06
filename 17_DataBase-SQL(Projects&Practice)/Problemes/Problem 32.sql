 --Get all Vehicle_Display_Name, year, Age for vehicles that their age between 15 and 25 years old 

 select * From 
 (
	select Vehicle_Display_Name, Year , Age = Year(GetDate()) - Year 
	From VehicleDetails VD
)R1
where Age between 15 and 25

