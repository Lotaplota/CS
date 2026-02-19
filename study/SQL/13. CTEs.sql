WITH CTE_Example AS (
	SELECT gender, AVG(salary) AS sal_avg, SUM(salary) AS sal_sum, MAX(salary) AS sal_max
    FROM employee_demographics AS dem
    JOIN employee_salary AS sal
		ON dem.employee_id = sal.employee_id
    GROUP BY gender
)
SELECT *
FROM CTE_Example;

WITH CTE_Example (Gender, sal_avg, sal_sum, sal_max) AS (
	SELECT gender, AVG(salary), SUM(salary), MAX(salary)
    FROM employee_demographics AS dem
    JOIN employee_salary AS sal
		ON dem.employee_id = sal.employee_id
    GROUP BY gender
)
SELECT *
FROM CTE_Example;

WITH CTE_Example AS (
	SELECT gender, AVG(salary) AS sal_avg, SUM(salary) AS sal_sum, MAX(salary) AS sal_max
    FROM employee_demographics
)
SELECT *
FROM CTE_Example;

WITH CTE1 AS (
	SELECT employee_id AS e_id, first_name, birth_date
    FROM employee_demographics
    WHERE birth_date > '1980-01-01'
), CTE2 AS (
	SELECT employee_id AS e_id, salary, occupation
    FROM employee_salary
    WHERE salary > 50000
)
SELECT *
FROM CTE1 JOIN CTE2
	ON CTE1.e_id = CTE2.e_id;