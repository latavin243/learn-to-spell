--
-- @lc app=leetcode id=175 lang=mysql
--
-- [175] Combine Two Tables
--

-- @lc code=start
# Write your MySQL query statement below
select
p.FirstName FirstName,
p.LastName LastName,
a.City City,
a.State State
from Person p
left outer join Address a
on a.PersonId=p.PersonId;

-- @lc code=end

-- select
-- FirstName,
-- LastName,
-- City,
-- State
-- from Person
-- left join Address
-- on Person.PersonId=Address.PersonId