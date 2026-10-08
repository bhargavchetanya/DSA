# Write your MySQL query statement below
SELECT a.student_id,
        a.student_name,
        c.subject_name,
        COUNT(b.subject_name) AS attended_exams
FROM Students a
CROSS JOIN Subjects c
LEFT JOIN Examinations b
ON a.student_id=b.student_id
AND c.subject_name=b.subject_name
GROUP BY a.student_id,c.subject_name
ORDER BY a.student_id,c.subject_name;
