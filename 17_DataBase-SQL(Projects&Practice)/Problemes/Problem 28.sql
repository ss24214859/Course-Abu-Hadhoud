--Get all vehicles that their body is 'Coupe' or 'Hatchback' or 'Sedan' and manufactured in year 2008 or 2020 or 2021

Select B.BodyName ,VD.* From Bodies B
join VehicleDetails VD on B.BodyID = VD.BodyID
where (BodyName in ('Coupe' , 'Hatchback' , 'Sedan')) and Year in(2008,2020,2021)