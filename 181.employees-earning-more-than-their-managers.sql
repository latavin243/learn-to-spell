--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below
select e.Name Employee
from Employee as e
join Employee as m
on e.ManagerId = m.Id
where e.Salary > m.Salary

-- @lc code=end

