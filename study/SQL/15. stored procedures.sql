CREATE PROCEDURE large_salaries()
SELECT *
FROM employee_salary
WHERE salary >= 50000;

CALL large_salaries(); # Idk if the parenthesis are necessary

DELIMITER $$
CREATE PROCEDURE large_salaries5()
BEGIN
	SELECT *
	FROM employee_salary
	WHERE salary >= 50000;
END $$
DELIMITER ;

CALL new_procedure();

DROP PROCEDURE IF EXISTS `salaryof`;
CREATE PROCEDURE salaryof(frist VARCHAR(20), scnd VARCHAR(20))
SELECT salary
FROM employee_salary
WHERE first_name = frist AND last_name = scnd;

CALL salaryof('Leslie', 'Knope');

SELECT employee_id
FROM employee_salary
WHERE first_name = 'Leslie';