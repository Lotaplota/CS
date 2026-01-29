SELECT first_name
FROM employee_demographics
UNION # By default, UNION is UNION DISTINCT
SELECT first_name
FROM employee_salary;

SELECT first_name AS firstt, last_name AS lastt, 'Old man' AS 'Label'
FROM employee_demographics
WHERE age > 40 AND gender = 'Male'
UNION
SELECT first_name, last_name, 'Old lady'
FROM employee_demographics
WHERE age > 40 AND gender = 'Female'
UNION
SELECT first_name, last_name, 'Well paid'
FROM employee_salary
WHERE salary > 70000
ORDER BY firstt;