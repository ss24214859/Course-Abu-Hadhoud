--Get the highest 3 manufacturers that make the highest number of models

select top 3 Make , count(ModelName) NumberOfModels From Makes M
join MakeModels Mm on MM.MakeID = M.MakeID
Group by Make
order by NumberOfModels desc