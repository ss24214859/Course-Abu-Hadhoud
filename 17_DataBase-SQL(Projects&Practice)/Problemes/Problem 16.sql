--Problem 16: Get all Makes that manufactures DriveTypeName = FWD

Select  distinct M.Make , D.DriveTypeName From VehicleDetails VD
join Makes M On M.MakeID = VD.MakeID
join DriveTypes D on D.DriveTypeID = VD.DriveTypeID
where (D.DriveTypeName = N'FWD')
order by M.Make


-- Get all Vehicles Makes that manufactures DriveTypeName = FWD


Select  M.Make , D.DriveTypeName ,  count(*) NumberOfVehicles From VehicleDetails VD
join Makes M On M.MakeID = VD.MakeID
join DriveTypes D on D.DriveTypeID = VD.DriveTypeID
Group By M.Make , D.DriveTypeName
Having (D.DriveTypeName = N'FWD')
order by M.Make
