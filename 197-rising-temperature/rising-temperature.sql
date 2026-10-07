# Write your MySQL query statement below
SELECT a.id AS Id
FROM Weather a
JOIN Weather b
ON DATEDIFF(b.recordDate,a.recordDate)=-1
WHERE a.temperature>b.temperature;