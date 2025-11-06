-- Get the highest number of models manufactured
select Max(NumberOfModels)as MaxNumberOfModels From 
(
	select m.Make ,count(m.Make) NumberOfModels  From Makes m
	join MakeModels mm on mm.MakeID = m.MakeID
	Group by m.Make
)R1

