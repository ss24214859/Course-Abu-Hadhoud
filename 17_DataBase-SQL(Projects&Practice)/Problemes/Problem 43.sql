-- Get Make and Total Number Of Doors Manufactured Per Make

select  m.Make , Sum(VD.NumDoors) TotalNumberOfDoors From VehicleDetails VD
join Makes m on m.MakeID = VD.MakeID
Group by Make
order by TotalNumberOfDoors desc
