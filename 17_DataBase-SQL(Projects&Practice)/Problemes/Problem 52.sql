--Get all employees that have manager or does not have manager along with Manager's name, incase no manager name show null

select E.*,Manegers.Name From Employees E
left join Employees Manegers on Manegers.EmployeeID = E.ManagerID;


