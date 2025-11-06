-- Get Total Number Of Doors Manufactured by 'Ford'

select  m.Make , Sum(VD.NumDoors) TotalNumberOfDoors From VehicleDetails VD
join Makes m on m.MakeID = VD.MakeID
Group by Make
Having m.Make = 'Ford'
