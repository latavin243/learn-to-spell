--
-- @lc app=leetcode id=182 lang=mysql
--
-- [182] Duplicate Emails
--

-- @lc code=start
# Write your MySQL query statement below
select distinct source.Email
from Person as source
join Person as reference
on source.Email = reference.Email
where source.Id != reference.Id

-- @lc code=end

-- select Email
-- from Person
-- group by Email
-- having count(*) > 1