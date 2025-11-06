 --Get all Vehicle_Display_Name, year and add extra column to calculate the age of the car then sort the results by age

 select Vehicle_Display_Name, Year , Age = Year(GetDate()) - Year 
	From VehicleDetails VD
 order by Age Desc
