INSERT INTO ft_table (login, creation_date, `group`)
SELECT last_name AS login, DATE(birthdate) AS creation_date, '3'
FROM user_card
WHERE
	last_name LIKE '%a%'
	AND
    CHAR_LENGTH(last_name) < 9
ORDER BY last_name ASC
LIMIT 10;