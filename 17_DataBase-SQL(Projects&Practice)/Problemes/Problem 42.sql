-- Get a table of unique Engine_CC and calculate tax per Engine CC as follows:
	-- 0 to 1000    Tax = 100
	-- 1001 to 2000 Tax = 200
	-- 2001 to 4000 Tax = 300
	-- 4001 to 6000 Tax = 400
	-- 6001 to 8000 Tax = 500
	-- Above 8000   Tax = 600
	-- Otherwise    Tax = 0
select * ,
case
	when R1.Engine_CC between 0 and 1000    Then 100
	when R1.Engine_CC between 1001 and 2000 Then 200
	when R1.Engine_CC between 2001 and 4000 Then 300
	when R1.Engine_CC between 4001 and 6000 Then 400
	when R1.Engine_CC between 6001 and 8000 Then 500
	when R1.Engine_CC > 8000				Then 600
	Else 0
end as Tax
From
(
	select distinct Engine_CC From VehicleDetails
)R1
order by Engine_CC



-- This SL is slow and not performance

select distinct Engine_CC ,
case
	when Engine_CC between 0 and 1000    Then 100
	when Engine_CC between 1001 and 2000 Then 200
	when Engine_CC between 2001 and 4000 Then 300
	when Engine_CC between 4001 and 6000 Then 400
	when Engine_CC between 6001 and 8000 Then 500
	when Engine_CC > 8000				Then 600
	Else 0
end as Tax From VehicleDetails
order by Engine_CC
