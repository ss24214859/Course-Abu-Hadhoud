--Get number vehicles made between 1950 and 2000 per make and order them by Number Of Vehicles Descending

select m.Make,Count(*) NumberOfVehicles from VehicleDetails VD
join Makes M on M.MakeID = VD.MakeID
where Year Between 1950 And 2000 
Group by m.Make 
order by NumberOfVehicles Desc

