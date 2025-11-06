--Get Number of Models Per Make

select Make , count(Make) as NumberOfModels From MakeModels mm
join Makes m on m.MakeID = mm.MakeID
Group By Make
order by NumberOfModels desc 
















