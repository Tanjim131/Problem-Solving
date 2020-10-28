# Write your MySQL query statement below


select MAX(salary) as SecondHighestSalary 
from Employee
where salary < (select MAX(salary) from Employee);

-----------------------------------------------------------------------

# Write your MySQL query statement below

select MAX(e1.salary) as SecondHighestSalary 
from Employee e1 join Employee e2
where e1.salary < e2.salary;