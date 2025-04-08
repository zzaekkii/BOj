SELECT b.BOOK_ID, a.AUTHOR_NAME,
    DATE_FORMAT(b.PUBLISHED_DATE, '%Y-%m-%d') AS 'PUBLISHED_DATE'
FROM BOOK AS b JOIN AUTHOR AS a ON b.AUTHOR_ID = a.AUTHOR_ID
WHERE b.CATEGORY = '경제'
ORDER BY b.PUBLISHED_DATE ASC;