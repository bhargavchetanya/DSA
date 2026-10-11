# Write your MySQL query statement below
SELECT MAX(d.num) AS num
FROM(
    SELECT num,COUNT(num) AS freq
    FROM MyNumbers
    GROUP BY num
    HAVING freq=1
)d;