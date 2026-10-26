# Write your MySQL query statement below
SELECT DISTINCT p1.product_id,
    COALESCE((SELECT p2.new_price
            FROM Products p2
            WHERE change_date<='2019-08-16'
            AND p2.product_id=p1.product_id
            ORDER BY change_date DESC
            LIMIT 1),10) AS price
FROM Products p1;