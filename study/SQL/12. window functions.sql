SELECT gender, salary, AVG(salary) OVER(PARTITION BY gender)
FROM employee_demographics AS dem
JOIN employee_salary AS sal
	ON dem.employee_id = sal.employee_id;

SELECT gender, salary, SUM(salary) OVER(PARTITION BY gender) AS 'salary sum'
FROM employee_demographics AS dem
JOIN employee_salary AS sal
	ON dem.employee_id = sal.employee_id;
    
SELECT gender, salary, SUM(salary) OVER(PARTITION BY gender ORDER BY dem.employee_id) AS 'rolling total'
FROM employee_demographics AS dem
JOIN employee_salary AS sal
	ON dem.employee_id = sal.employee_id;
    
SELECT dem.first_name, gender, salary,
ROW_NUMBER() OVER(PARTITION BY gender ORDER BY salary DESC) as 'row number',
RANK() OVER(PARTITION BY gender ORDER BY salary DESC) AS 'rank',
DENSE_RANK() OVER(PARTITION BY gender ORDER BY salary DESC) 'dense rank'
FROM employee_demographics AS dem
JOIN employee_salary AS sal
	ON dem.employee_id = sal.employee_id;