SELECT COUNT(*) as 'films'
FROM member_history
WHERE
	DATE(date) BETWEEN '2006-10-30' AND '2007-07-27'
OR
	DATE(date) LIKE '%-12-24';