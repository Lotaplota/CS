SELECT first_name, LENGTH(first_name) AS n
FROM employee_demographics
ORDER BY 2;

SELECT UPPER(last_name), LOWER(first_name)
FROM employee_demographics;

SELECT TRIM('  whitespace  '); # There's also LTRIM and RTRIM;

SELECT LEFT(first_name, LENGTH(first_name) / 2), RIGHT(first_name, LENGTH(first_name)/2)
FROM employee_demographics;

-- Selects the substring that starts in the 4th character and is 2 characters long
SELECT first_name, SUBSTRING(first_name, 4, 2)
FROM employee_demographics;

SELECT first_name, SUBSTRING(birth_date, 6, 2) AS 'birth month'
FROM employee_demographics
ORDER BY 2;

-- REPLACE, LOCATE and CONCAT -----------------------------------
SELECT first_name, REPLACE(first_name, 'a', 'z')
FROM employee_demographics;

SELECT first_name, LOCATE('nn', first_name) AS pos
FROM employee_demographics
WHERE IF(LOCATE('nn', first_name) != 0, 'true', 'false') = 'true';

SELECT CONCAT(first_name, ' ', last_name) AS 'full name'
FROM employee_demographics;