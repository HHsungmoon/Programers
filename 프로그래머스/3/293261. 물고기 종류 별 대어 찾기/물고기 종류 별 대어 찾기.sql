-- 코드를 작성해주세요


SELECT ID, FISH_NAME, LENGTH
FROM FISH_INFO F LEFT JOIN FISH_NAME_INFO FN ON F.FISH_TYPE = FN.FISH_TYPE
WHERE LENGTH = (SELECT MAX(LENGTH) FROM FISH_INFO WHERE FISH_TYPE = F.FISH_TYPE)