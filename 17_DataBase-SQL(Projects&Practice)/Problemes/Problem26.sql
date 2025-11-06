--Get all vehicles that their body is 'Sport Utility' and Year > 2020

Select B.BodyName ,VD.* From Bodies B
join VehicleDetails VD on B.BodyID = VD.BodyID
where BodyName = 'Sport Utility' and Year > 2020;