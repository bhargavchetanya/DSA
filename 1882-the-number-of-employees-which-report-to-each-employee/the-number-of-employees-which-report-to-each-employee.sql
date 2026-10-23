# Write your MySQL query statement below
SELECT e1.employee_id,e1.name,
    COUNT(e2.reports_to) AS reports_count,
    ROUND(AVG(e2.age)) AS average_age
FROM Employees e1 JOIN Employees e2 
WHERE e1.employee_id=e2.reports_to
GROUP BY e1.employee_id
HAVING reports_count>=1
ORDER BY e1.employee_id;