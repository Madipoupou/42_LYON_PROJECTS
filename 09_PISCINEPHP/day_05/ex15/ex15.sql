SELECT REVERSE(SUBSTRING(phone_number, 2, CHAR_LENGTH(phone_number))) as 'rebmunenohp'
FROM distrib
WHERE phone_number LIKE '05%';