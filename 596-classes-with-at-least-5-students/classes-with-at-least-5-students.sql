# Write your MySQL query statement below
SELECT DISTINCT class
FROM Courses 
WHERE (class) IN(
    SELECT class
    FROM Courses
    GROUP BY class
    HAVING COUNT(student)>=5
);