-- Get all FuelTypes , each time the result should be showed in random order
-- Note that the NewID() function will generate GUID for each row 

select top 1 * From FuelTypes
order by newID()