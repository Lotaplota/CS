SELECT first_name, last_name, age,
CASE
	WHEN age <= 30 THEN 'Young'
    WHEN age BETWEEN 31 AND 50 THEN 'Old'
    WHEN age >= 45 THEN "On death's door"
END AS 'age bracket'
FROM employee_demographics;

-- EXERCISE: Salary Increase
SELECT first_name, last_name, department_name, salary,
CASE
	WHEN department_name = 'Finance' THEN salary * 1.1 # This one needs to happen first because apparently a row can only be affected by a CASE statement one time
	WHEN salary < 50000 THEN salary * 1.05
    WHEN salary >= 50000 THEN salary * 1.07
END AS 'new salary'
FROM employee_salary
JOIN parks_departments
ON dept_id = department_id;