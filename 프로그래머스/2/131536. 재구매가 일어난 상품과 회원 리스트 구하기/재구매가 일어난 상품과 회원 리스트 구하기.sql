SELECT user_id, product_id FROM online_sale
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(*) >= 2
ORDER BY user_id asc,
product_id desc;