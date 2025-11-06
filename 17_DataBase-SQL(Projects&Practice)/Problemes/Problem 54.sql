--Get All Employees managed by 'Mohammed'

select E.* , Managers.Name From Employees E
join Employees Managers on Managers.EmployeeID = E.ManagerID
where Managers.Name = 'Mohammed'
