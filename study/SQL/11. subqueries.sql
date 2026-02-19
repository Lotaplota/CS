SELECT *
FROM employee_demographics
WHERE employee_id IN ( # The operator IN requires the operand to have only one collumn
	SELECT employee_id
    FROM employee_salary
    WHERE dept_id = 1
);

-- This query does the same as the query above, but uses JOIN instead of doing a subquery
SELECT *
FROM employee_demographics AS dem
JOIN employee_salary AS sal
ON dem.employee_id = sal.employee_id
WHERE dept_id = 1;

SELECT first_name, salary, (
	SELECT AVG(salary)
    FROM employee_salary
) AS avg_sal, (
	SELECT (salary - avg_sal) / avg_sal
) AS ratio
FROM employee_salary;

SELECT AVG(`MAX(age)`) as 'average of max ages of genders this is so confusing...'
FROM (
	SELECT gender, AVG(age), MAX(age), MIN(age)
    FROM employee_demographics
    GROUP BY gender
) AS agg_table;

-- Just an example of using a table of only one entry as a math operand
-- Don't hink too much about it...
SELECT 2 * (
	SELECT AVG(`MAX(age)`) as 'average of max ages of genders this is so confusing...'
	FROM (
		SELECT gender, AVG(age), MAX(age), MIN(age)
		FROM employee_demographics
		GROUP BY gender
	) AS agg_table
);