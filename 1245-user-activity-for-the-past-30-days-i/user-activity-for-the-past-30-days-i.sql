# Write your MySQL query statement below
SELECT activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM Activity
GROUP BY day
HAVING day BETWEEN '2019-06-28' AND '2019-07-27';