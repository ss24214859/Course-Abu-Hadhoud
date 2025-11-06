--Get all vehicles that has one of the Max 3 Engine CC
select  m.Make , VD.* From VehicleDetails VD
join Makes m on m.MakeID = VD.MakeID
where Engine_CC in ( select  distinct Top 3  Engine_CC From VehicleDetails Order by Engine_CC Desc)
Order by Engine_CC Desc
