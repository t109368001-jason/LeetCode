# Write your MySQL query statement below
SELECT Users.user_id,
    CONCAT(
        UPPER(LEFT(Users.name, 1)),
        LOWER(SUBSTRING(Users.name, 2))
    ) as name
FROM Users
ORDER BY Users.user_id ASC;