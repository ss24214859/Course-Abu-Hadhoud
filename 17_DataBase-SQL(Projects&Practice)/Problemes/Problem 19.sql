--Get total vehicles per DriveTypeName Per Make then filter only results with total > 10,000

	Select    M.Make , D.DriveTypeName , count(*) Total
	From VehicleDetails VD
			join Makes M On M.MakeID = VD.MakeID
			join DriveTypes D on D.DriveTypeID = VD.DriveTypeID
	Group by M.Make , D.DriveTypeName 
	Having (count(*)> 10000)
	Order By M.Make ASC, 
	 Total Desc