--Get the Lowest Manufacturers manufactured the lowest number of models ,
--remember that they could be more than one manufacturer have the same lowest number of models

select m.Make ,count(m.Make) NumberOfModels  From Makes m
	join MakeModels mm on mm.MakeID = m.MakeID
	Group by m.Make
	Having count(m.Make) = 
( 
	select min(NumberOfModels)as LowestNumberOfModels From 
	(
	
		select m.Make ,count(m.Make) NumberOfModels  From Makes m
		join MakeModels mm on mm.MakeID = m.MakeID
		Group by m.Make
	)R1
)






