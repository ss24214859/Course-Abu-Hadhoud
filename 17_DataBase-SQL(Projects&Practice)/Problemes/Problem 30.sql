--Get all Vehicle_Display_Name, NumDoors and add extra column to describe number of doors by words, and if door is null display 'Not Set'

select  Vehicle_Display_Name ,  NumDoors ,
Case 
	when NumDoors is Null Then 'Not Set'
	when NumDoors = 0 Then 'Zero Doors'
	when NumDoors = 1 Then 'one Doors'
	when NumDoors = 2 Then 'Tow Doors'
	when NumDoors = 3 Then 'Three Doors'
	when NumDoors = 4 Then 'Four Doors'
	when NumDoors = 5 Then 'Five Doors'
	when NumDoors = 6 Then 'Six Doors'
	when NumDoors = 8 Then 'Eight Doors'
	else 'UnKnown'
end as DoorDescription
from VehicleDetails
where NumDoors = 0
order by Vehicle_Display_Name