SELECT i.ITEM_ID, i.ITEM_NAME
FROM ITEM_INFO AS i JOIN ITEM_TREE AS t ON i.ITEM_ID = t.ITEM_ID
WHERE t.PARENT_ITEM_ID IS NULL
ORDER BY i.ITEM_ID ASC;