SELECT last_name, salary
FROM employee_salary
WHERE first_name = 'Leslie';

SELECT *
FROM employee_salary
WHERE salary < 50000;

SELECT *
FROM employee_demographics
WHERE birth_date > '1980-01-01'
OR NOT gender = 'Male';

SELECT *
FROM employee_demographics
WHERE (first_name = 'Leslie' AND age = 44) OR age > 44;

-- LIKE statement
SELECT *
FROM employee_demographics
WHERE first_name
LIKE 'a%'; -- Starts with A then has anything after it

SELECT *
FROM employee_demographics
WHERE first_name
LIKE 'a__'; -- Starts with A and has two characters after

SELECT *
FROM employee_demographics
WHERE first_name
LIKE 'a___%'; -- Starts with A, has at least 3 characters after

SELECT *
FROM employee_demographics
WHERE birth_date
LIKE '%-08-%'; -- Was born in the month of august