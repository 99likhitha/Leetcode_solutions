# Write your MySQL query statement below
Select name as Employee from Employee where salary > 
(select salary from Employee as a where a.id = Employee.managerId);