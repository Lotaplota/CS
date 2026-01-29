-- Groups by gender and displays the genders that the avarage age of the people is bigger then 40
SELECT gender, AVG(age)
FROM employee_demographics
GROUP BY gender
HAVING AVG(age) > 40;

-- Displays the manager occupations which salaries are bigger than 70000
SELECT occupation, AVG(salary)
FROM employee_salary
WHERE occupation LIKE '%manager%'
GROUP BY occupation
HAVING AVG(salary) > 70000; # HAVING only works with an aggregate function after the GROUP BY has already occurred