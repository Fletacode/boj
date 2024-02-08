
SELECT CATEGORY, PRICE AS 'MAX_PRICE',PRODUCT_NAME
FROM FOOD_PRODUCT AS A
WHERE CATEGORY IN ("과자","국","김치","식용유")
     AND
PRICE =
(
    SELECT MAX(PRICE) FROM FOOD_PRODUCT AS B
   WHERE A.CATEGORY = B.CATEGORY
) 
ORDER BY  PRICE DESC;

/*
SELECT MAX(PRICE) ,PRODUCT_NAME FROM FOOD_PRODUCT 
    WHERE CATEGORY = "과자" OR 
     CATEGORY = "국" OR CATEGORY = "김치" OR CATEGORY = "식용유"
    GROUP BY CATEGORY


김치	19000	맛있는배추김치
식용유	8950	맛있는마조유
국	2900	맛있는김치찌개
밥	1950	맛있는잡곡밥
과자	1950	맛있는허니버터칩


SELECT *
FROM FOOD_PRODUCT
*/