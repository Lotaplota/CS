-- works like DISTINCT
SELECT gender # SELECT and GROUP BY shoud match, and it's something to do with aggregate functions
FROM employee_demographics
GROUP BY gender;

-- Displays the gender and the average age of the people in said gender
SELECT gender, AVG(age)
FROM employee_demographics
GROUP BY gender;

-- Displays the average salary of each occupation
SELECT occupation, avg(salary)
FROM employee_salary
GROUP BY occupation;

-- Displays the distinct pairs of occupations and salaries
SELECT occupation, salary
FROM employee_salary
GROUP BY occupation, salary;

-- Displays some aggregate information about the genders and counts how many people are there
SELECT gender, COUNT(age), AVG(age), MAX(age), MIN(age)
FROM employee_demographics
GROUP BY gender;

-- ORDER BY ------------------------
SELECT *
FROM employee_demographics
ORDER BY first_name;

SELECT *
FROM employee_demographics
ORDER BY gender ASC, age DESC;

-- Does the same as the above, but shouldn't really be used
SELECT *
FROM employee_demographics
ORDER BY 5 ASC, 4 DESC;