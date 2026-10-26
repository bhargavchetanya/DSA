# Write your MySQL query statement below
SELECT person_name
FROM(
    SELECT person_name,turn,
        SUM(weight) OVER (ORDER BY turn) AS total
    FROM Queue
    ORDER BY turn DESC
)t
WHERE total<=1000
LIMIT 1;