--Return found=1 if there is any vehicle made in year 1950
 
select(select Found =1 
where 
exists (
			select top(1) * From VehicleDetails where Year = 1950
)) R1

select R1.Found From R1   