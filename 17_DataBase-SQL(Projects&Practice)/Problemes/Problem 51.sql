-- Get all employees that have manager along with Manager's name.
-- this will select all data from employees that are managed by someone along with their manager name, 
-- employees that have no manager will not be selected because we used inner join 
-- Note we used inner join on the same table with diffrent alliace.


select E.*,Manegers.Name From Employees E
join Employees Manegers on Manegers.EmployeeID = E.ManagerID;


