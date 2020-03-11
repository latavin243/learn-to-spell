--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--

-- @lc code=start
# Write your MySQL query statement below
select c.Name as Customers
from Customers as c
left join Orders as o
on c.Id = o.CustomerId
where o.Id is NULL

-- @lc code=end

