# Write your MySQL query statement below
SELECT ROUND(SUM(
        CASE WHEN d.event_date = d.first_login + INTERVAL 1 DAY
        THEN 1 ELSE 0 END
        )/COUNT(DISTINCT d.player_id)
        ,2) AS fraction 
FROM (
    SELECT *, MIN(event_date) OVER (PARTITION BY player_id) AS first_login
    FROM Activity
) d
;