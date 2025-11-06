--Get all vehicles that have the minimum Engine_CC

select Vehicle_Display_Name From VehicleDetails
where Engine_CC = (select Min(Engine_CC) From VehicleDetails)










