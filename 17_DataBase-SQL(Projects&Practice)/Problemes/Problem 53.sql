--Get all employees that have manager or does not have manager along with
--Manager's name, incase no manager name the same employee name as manager to himself


select E.*,
case
	when Manegers.Name is Null Then  E.Name
	Else 
	Manegers.Name
End as MangerName

From Employees E

left join Employees Manegers on Manegers.EmployeeID = E.ManagerID;


