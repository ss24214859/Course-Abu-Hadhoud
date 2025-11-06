--Get all vehicles that have the Maximum  Engine_CC

select Vehicle_Display_Name From VehicleDetails
where Engine_CC = (select Max(Engine_CC) From VehicleDetails)





-- Get all vehicles that have the Maximum Engin_CC

Select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where Engine_CC = ( select  Max(Engine_CC) as MinEngineCC  from VehicleDetails )