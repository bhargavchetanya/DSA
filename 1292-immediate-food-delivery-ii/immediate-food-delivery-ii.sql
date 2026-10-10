# Write your MySQL query statement below
SELECT ROUND(
    SUM(CASE WHEN d.order_date=d.customer_pref_delivery_date
    THEN 1 ELSE 0 END)*100.00/
    COUNT(d.customer_id),2) AS immediate_percentage
FROM Delivery d
WHERE (d.customer_id,d.order_date) IN(
    SELECT customer_id,MIN(order_date)
    FROM Delivery 
    GROUP BY customer_id
);