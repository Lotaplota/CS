SELECT sal.first_name, age, occupation, salary
FROM employee_demographics AS dem
JOIN employee_salary AS sal # By default, JOIN is actually INNER JOIN
	ON dem.employee_id = sal.employee_id;
    
-- Outer joins -----------------------------------

SELECT sal.first_name, age, occupation, salary
FROM employee_demographics AS dem
RIGHT JOIN employee_salary AS sal # Every entry on the SECOND table will be represented in a row
	ON dem.employee_id = sal.employee_id;
    
-- Self joins ------------------------------------

SELECT emp1.first_name, emp1.employee_id, emp2.employee_id, emp2.first_name
FROM employee_salary AS emp1
JOIN employee_salary AS emp2
	ON emp1.employee_id + 1 = emp2.employee_id;

SELECT first_name, department_name
FROM employee_salary
JOIN parks_departments
	ON dept_id = department_id
ORDER BY department_name;

SELECT * FROM employee_demographics; SELECT * FROM employee_salary; SELECT * FROM parks_departments;

-- Joins the three tables then displays some information of each
SELECT sals.first_name, sals.occupation, salary, department_name
FROM employee_demographics AS dems
RIGHT JOIN employee_salary AS sals
	ON dems.employee_id = sals.employee_id
JOIN parks_departments AS depts
	ON sals.dept_id = depts.department_id;