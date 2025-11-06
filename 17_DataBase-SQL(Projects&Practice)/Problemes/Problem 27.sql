--Get all vehicles that their Body is 'Coupe' or 'Hatchback' or 'Sedan'

Select B.BodyName ,VD.* From Bodies B
join VehicleDetails VD on B.BodyID = VD.BodyID
where BodyName in ('Coupe' , 'Hatchback' , 'Sedan')