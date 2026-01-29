-- Displays the top 4
SELECT *
FROM employee_demographics
LIMIT 4;

-- Displays the 4 oldest employees
SELECT *
FROM employee_demographics
ORDER BY age DESC
LIMIT 4;

-- Displays the fourth oldest employee
SELECT first_name, last_name
FROM employee_demographics
ORDER BY age DESC
LIMIT 3, 1;

-- Aliasing

-- Groups the people into their genders, renames AVG(age), displays the gender that the average age of the people in it is bigger then 40
SELECT gender, AVG(age) AS avg_age
FROM employee_demographics
GROUP BY gender
HAVING avg_age > 40;