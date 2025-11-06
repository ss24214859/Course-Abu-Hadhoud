-- Problem 17: Get total Makes that Mantufactures DriveTypeName=FWD
select count(*) as MakesWithFWD 
From (
	Select  distinct M.Make , D.DriveTypeName 
	From VehicleDetails VD
			join Makes M On M.MakeID = VD.MakeID
			join DriveTypes D on D.DriveTypeID = VD.DriveTypeID
	where (D.DriveTypeName = N'FWD')

)R1
