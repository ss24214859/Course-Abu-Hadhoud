--Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside

select m.Make,Count(*) NumberOfVehicles , (select count(*) from VehicleDetails) as TotalVehicles from VehicleDetails VD
join Makes M on M.MakeID = VD.MakeID
where (Year Between 1950 And 2000)
Group by M.Make
order by NumberOfVehicles Desc



