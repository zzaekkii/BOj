SELECT b.TITLE, b.BOARD_ID, r.REPLY_ID, r.WRITER_ID, r.CONTENTS, DATE_FORMAT(r.CREATED_DATE, '%Y-%m-%d') AS CREATED_DATE
FROM USED_GOODS_BOARD AS b INNER JOIN USED_GOODS_REPLY AS r ON b.BOARD_ID = r.BOARD_ID
# WHERE YEAR(r.CREATED_DATE) = 2022 AND MONTH(r.CREATED_DATE) = 10
WHERE SUBSTR(b.CREATED_DATE, 1, 7) = '2022-10'
ORDER BY r.CREATED_DATE ASC, b.TITLE ASC;
