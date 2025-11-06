-- Get MakeID , Make, SubModelName for all vehicles that have SubModelName 'Elite'

Select distinct VD.MakeID,m.Make, sm.SubModelName 
From	VehicleDetails VD
join Makes m on m.MakeID = VD.MakeID
join SubModels sm on sm.SubModelID = VD.SubModelID
where sm.SubModelName = 'Elite'