SELECT c.category, COUNT(t.account_id) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL SELECT 'Average Salary'
    UNION ALL SELECT 'High Salary'
) c
LEFT JOIN (
    SELECT account_id,
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income >= 20000 AND income <= 50000 THEN 'Average Salary'
            WHEN income > 50000 THEN 'High Salary'
        END AS category
    FROM Accounts
) t ON c.category = t.category
GROUP BY c.category;