# Write your MySQL query statement below
SELECT user_id,
        COUNT(user_id) AS followers_count
FROM Followers
GROUP by user_id
ORDER BY user_id;