--Get total vehicles per DriveTypeName Per Make and order them per make asc then per total Desc

	Select   M.Make , D.DriveTypeName , count(*) Total
	From VehicleDetails VD
			join Makes M On M.MakeID = VD.MakeID
			join DriveTypes D on D.DriveTypeID = VD.DriveTypeID
	Group by M.Make , D.DriveTypeName 
	Order By M.Make ASC, 
	 Total Desc