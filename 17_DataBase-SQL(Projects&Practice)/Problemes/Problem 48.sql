--Get the highest Manufacturers manufactured the highest number of models ,
--remember that they could be more than one manufacturer have the same high number of models

select m.Make ,count(m.Make) NumberOfModels  From Makes m
	join MakeModels mm on mm.MakeID = m.MakeID
	Group by m.Make
	Having count(m.Make) = 
( 
	select Max(NumberOfModels)as MaxNumberOfModels From 
	(
	
		select m.Make ,count(m.Make) NumberOfModels  From Makes m
		join MakeModels mm on mm.MakeID = m.MakeID
		Group by m.Make
	)R1
)








							)