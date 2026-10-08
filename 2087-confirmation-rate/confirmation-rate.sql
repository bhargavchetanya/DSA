# Write your MySQL query statement below
SELECT a.user_id,
        COALESCE(ROUND(COUNT(CASE WHEN b.action IN('confirmed')THEN 1 END)/
            COUNT(CASE WHEN b.action IN ('confirmed','timeout',NULL) THEN 1 END),2)
            ,0)
        AS confirmation_rate
FROM Signups a
LEFT JOIN Confirmations b
ON a.user_id=b.user_id
GROUP BY a.user_id;